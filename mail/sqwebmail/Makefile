# $NetBSD: Makefile,v 1.10 2002/09/18 21:15:13 jlam Exp $

DISTNAME=	sqwebmail-3.3.1
CATEGORIES=	www
COMMENT=	webmail CGI for access to local Maildir-style mailboxes
HOMEPAGE=	http://www.inter7.com/sqwebmail/

DEPENDS+=	courier-auth>=0.37.1nb1:../../mail/courier-auth
DEPENDS+=	courier-maildirmake>=0.37.1nb1:../../mail/courier-maildirmake

USE_BUILDLINK_ONLY=	yes
USE_PERL5=		yes
REPLACE_PERL=		sysconftool

.include "../../mail/courier-auth/Makefile.common"

.if defined(_STRIPFLAG_INSTALL) && !empty(_STRIPFLAG_INSTALL:M-s)
INSTALL_TARGET=         install-strip
.endif

MAIL_GROUP?=	mail

STATEDIR=		/var/sqwebmail
CACHEDIR=		${STATEDIR}/cache
CALENDARDIR=		${STATEDIR}/calendar
IMAGEDIR=		${DATADIR}/sqwebmail/images
HTMLDIR=		${PREFIX}/share/doc/html/sqwebmail

CONFIGURE_ARGS+=	--with-cachedir=${CACHEDIR}
CONFIGURE_ARGS+=	--with-calendardir=${CALENDARDIR}
CONFIGURE_ARGS+=	--with-cacheowner=${ROOT_USER}
CONFIGURE_ARGS+=	--with-mailer=/usr/sbin/sendmail
CONFIGURE_ARGS+=	--enable-https=auto
CONFIGURE_ARGS+=	--enable-cgibindir=${PREFIX}/libexec/cgi-bin
CONFIGURE_ARGS+=	--enable-imagedir=${IMAGEDIR}
CONFIGURE_ARGS+=	--enable-imageurl=/images/sqwebmail

MIME_TYPES=		${PKG_SYSCONFDIR}/mime.types:${PKG_SYSCONFBASE}/httpd/mime.types:${PREFIX}/etc/mime.types:/etc/mime.types
CONFIGURE_ARGS+=	--enable-mimetypes="${MIME_TYPES}"
CONFIGURE_ARGS+=	--with-ispell="${LOCALBASE}/bin/ispell"

PKG_GROUPS=             ${MAIL_GROUP}

OWN_DIRS=		${STATEDIR}
OWN_DIRS_PERMS=		${CACHEDIR} ${ROOT_USER} ${ROOT_GROUP} 0755
OWN_DIRS_PERMS+=	${CALENDARDIR} ${ROOT_USER} ${MAIL_GROUP} 0755
OWN_DIRS_PERMS+=	${CALENDARDIR}/public ${ROOT_USER} ${MAIL_GROUP} 0755
OWN_DIRS_PERMS+=	${CALENDARDIR}/private ${ROOT_USER} ${MAIL_GROUP} 0750
OWN_DIRS_PERMS+=	${CALENDARDIR}/localcache ${ROOT_USER} ${MAIL_GROUP} 0700

SYSCONFTOOL=		${PREFIX}/sbin/sqwebmail.sysconftool
GEN_FILES=		ldapaddressbook

CONF_FILES=		${EGDIR}/authmodulelist ${PKG_SYSCONFDIR}/authmodulelist
.for FILE in ${GEN_FILES}
CONF_FILES+=		${EGDIR}/${FILE}.dist ${PKG_SYSCONFDIR}/${FILE}
.endfor
CONF_FILES_PERMS=	# empty
.for FILE in ldapsearch sendit.sh
CONF_FILES_PERMS+=	${DATADIR}/sqwebmail/${FILE}			\
			${PKG_SYSCONFDIR}/${FILE}			\
			${ROOT_USER} ${ROOT_GROUP} 0755
.endfor

FILES_SUBST+=		SYSCONFTOOL=${SYSCONFTOOL:Q}
FILES_SUBST+=		GEN_FILES=${GEN_FILES:Q}
MESSAGE_SUBST+=		IMAGEDIR=${IMAGEDIR}

pre-configure: configure-init

post-configure:
	cd ${WRKSRC}/ldapaddressbook; for file in ldapsearch; do	\
		${SED}	-e "s|@SED@|${SED}|g" $${file} > $${file}.new;	\
		${MV} -f $${file}.new $${file};				\
	done

post-install:
	${INSTALL_SCRIPT} ${WRKSRC}/sysconftool ${SYSCONFTOOL}
	for file in ldapaddressbook.dist; do				\
		${INSTALL_DATA} ${PKG_SYSCONFDIR}/$${file} ${EGDIR};	\
		${RM} -f ${PKG_SYSCONFDIR}/$${file};			\
	done
	cd ${WRKSRC}; ${INSTALL_DATA} sqwebmail/webmail.authpam		\
		${EGDIR}/webmail.pam
	${INSTALL_DATA_DIR} ${HTMLDIR} ${HTMLDIR}/sqwebmail ${HTMLDIR}/pcp
	cd ${WRKSRC}; ${INSTALL_DATA} COPYING INSTALL.html ${HTMLDIR}
	cd ${WRKSRC}/pcp; ${INSTALL_DATA} README.html ${HTMLDIR}/pcp
	cd ${WRKSRC}/sqwebmail; ${INSTALL_DATA} BUGS.html SECURITY.html	\
		${HTMLDIR}/sqwebmail

.include "../../mk/bsd.pkg.install.mk"
.include "../../mk/bsd.pkg.mk"
