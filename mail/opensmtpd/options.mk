# $NetBSD: options.mk,v 1.4 2024/03/02 17:01:12 vins Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.opensmtpd

PKG_SUPPORTED_OPTIONS=	mailwrapper pam

.if ${OPSYS} != "OpenBSD"
PKG_SUGGESTED_OPTIONS+=	pam
.else
CONFIGURE_ARGS+=	--with-auth-bsdauth
.endif

.if exists(/etc/mailer.conf) || exists(/etc/mail/mailer.conf) || exists(${PKG_SYSCONFDIR}/mailer.conf)
PKG_SUGGESTED_OPTIONS+=	mailwrapper
.endif

PLIST_VARS+=		mailwrapper pam

.include "../../mk/bsd.options.mk"

#
# PAM support
#
.if !empty(PKG_OPTIONS:Mpam)
.  include "../../mk/pam.buildlink3.mk"

CONFIGURE_ARGS+=	--with-auth-pam=smtp

PAMDIR=		share/examples/pam.d
MAKE_DIRS+=	${PAMDIR}

INSTALLATION_DIRS+=	${PAMDIR}

PLIST.pam=		yes

.PHONY:	pam-install

pam-install:
	${INSTALL_DATA} ${FILESDIR}/smtp.conf	\
		${DESTDIR}${PREFIX}/${PAMDIR}/smtp
.endif

#
# MTA symlinks
# Create the appriopriate symbolic links to `smtpctl' if mailwrapper is
# unavailable. This is done to accomodate clients that require historical
# interfaces such as sendmail, newaliases or makemap.
# The smtpctl utility can operate in compatibility mode if called with
# the historical name.
#
.if !empty(PKG_OPTIONS:Mmailwrapper)
post-install: doc-install pam-install
	${INSTALL_DATA} ${WRKSRC}/mailer.conf \
		${DESTDIR}${EGDIR}/mailer.conf
	${RUN}${LN} -sf ${PREFIX}/sbin/smtpctl \
		${DESTDIR}${PREFIX}/libexec/opensmtpd/makemap

PLIST.mailwrapper=	yes

.else

CONFLICTS+=	courier-mta-[0-9]* fastforward>=0.51nb2 sendmail-[0-9]*
CONFLICTS+=	esmtp>=1.2 nullmailer-[0-9]* postfix-[0-9]* qmail-[0-9]*

post-install: doc-install pam-install
.  for i in mailq makemap newaliases sendmail
	${RUN}${LN} -sf ${PREFIX}/sbin/smtpctl	\
		${DESTDIR}${PREFIX}/sbin/${i}
.  endfor

PLIST_SRC+=	PLIST.nowrap
.endif
