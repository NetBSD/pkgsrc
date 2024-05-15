# $NetBSD: Makefile,v 1.69 2024/05/15 10:57:04 wiz Exp $

DISTNAME=	courier-${COURIER_VERSION}
PKGNAME=	${DISTNAME:S/-/-mta-/}
PKGREVISION=	1
CATEGORIES=	mail

CONFLICTS+=	esmtp>=1.2 postfix-[0-9]* qmail-[0-9]* sendmail-[0-9]*

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Courier mail transport agent
HOMEPAGE=	https://www.courier-mta.org/

DEPENDS+=	courier-maildir>=${COURIER_VERSION}:../../mail/courier-maildir
DEPENDS+=	couriertcpd>=${COURIER_VERSION}:../../net/couriertcpd
DEPENDS+=	maildrop>=2.5.0:../../mail/maildrop
DEPENDS+=	gnupg2-[0-9]*:../../security/gnupg2
DEPENDS+=	wget-[0-9]*:../../net/wget

USE_TOOLS+=		gmake perl:run realpath
USE_LANGUAGES=		c c++

.include "Makefile.common"

PLIST_SRC+=		${PKGDIR}/PLIST

.include "pkginstall.mk"
.include "options.mk"

CONFIGURE_ARGS.NetBSD+=	ac_cv_path_REHASH=${FALSE:Q}

USERGROUP_PHASE=	configure

CONFIGURE_ENV+=		CERTTOOL=${COURIER_CERTTOOL:Q}
CONFIGURE_ENV+=		OPENSSL=${COURIER_OPENSSL:Q}
CONFIGURE_ENV+=		PROCMAIL=${PREFIX}/bin/procmail

CONFIGURE_ARGS+=	--datadir=${DATADIR}
CONFIGURE_ARGS+=	--with-mailuid=${PKG_UID.${COURIER_USER}}
CONFIGURE_ARGS+=	--with-mailgid=${PKG_GID.${COURIER_GROUP}}
CONFIGURE_ARGS+=	--with-paranoid-smtpext
CONFIGURE_ARGS+=	--with-piddir=${COURIER_STATEDIR}/tmp
CONFIGURE_ARGS+=	--with-transport=${COURIER_TRANSPORTS:M*:Q}
#CONFIGURE_ARGS+=	--with-certdb=${SSLCERTS}

# This argument is actually here just to make the "webmail" configure
# script work.  The value is not actually used since in reality, we are
# using the sqwebmail package to provide the Courier webmail component.
CONFIGURE_ARGS+=	--enable-mimetypes=/nonexistent

INSTALL_DIRS=		webadmin courier
INSTALL_AM_MAKEFLAGS+=	sysconfdir=${EGDIR:Q}
INSTALL_AM_MAKEFLAGS+=	htmldocdir=${DOCDIR:Q}
INSTALL_MAKE_FLAGS=	${MAKE_FLAGS} AM_MAKEFLAGS=${INSTALL_AM_MAKEFLAGS:Q}

SUBST_CLASSES+=		courier
SUBST_FILES.courier=	\
			courier/doc/mkesmtpdcert.html.in		\
			courier/filters/courierfilter.8.in		\
			courier/filters/courierfilter.html.in		\
			courier/module.esmtp/esmtpd-msa.dist.in		\
			courier/module.esmtp/esmtpd-ssl.dist.in		\
			courier/module.esmtp/esmtpd.dist.in		\
			courier/module.esmtp/mkesmtpdcert.in
SUBST_SED.courier=	-e "s|^ESMTPDSTART=.*|ESMTPDSTART=YES|g"
SUBST_SED.courier+=	-e "s|^ESMTPDSSLSTART=.*|ESMTPDSSLSTART=YES|g"
SUBST_SED.courier+=	-e "s|@mydatadir@|@sysconfdir@|g"
SUBST_SED.courier+=	-e "s|@datadir@/esmtpd.pem|@sysconfdir@/esmtpd.pem|g"
SUBST_SED.courier+=	-e "s|@datadir@/esmtpd.rand|@sysconfdir@/esmtpd.rand|g"
SUBST_SED.courier+=	-e "s|@libexecdir@/filters|@libexecdir@/courier/filters|g"
SUBST_STAGE.courier=	pre-configure

SUBST_CLASSES+=		paths
SUBST_FILES.paths=	${WRKDIR}/mailer.conf
SUBST_VARS.paths=	PREFIX
SUBST_STAGE.paths=	pre-configure

REPLACE_PERL+=	courier/webadmin/*.pl courier/webadmin/*.pl.in webadmin/*.pl courier/filters/perlfilter/*.pl

CHECK_WRKREF_SKIP+=	bin/courier-config

SPECIAL_PERMS+=	${DATADIR}/filterctl ${COURIER_USER} ${COURIER_GROUP} 0500
SPECIAL_PERMS+=	${PREFIX}/sbin/courierfilter  ${COURIER_USER} \
		${COURIER_GROUP} 0500

LIBS.SunOS+=	-lsocket -lnsl

.include "../../lang/perl5/buildlink3.mk"
.include "../../security/courier-authlib/buildlink3.mk"

post-extract:
	${CP} ${FILESDIR}/mailer.conf ${WRKDIR}/mailer.conf

post-build:
	${TOUCH} ${WRKDIR}/locallowercase

post-install:
	cd ${WRKSRC}/courier && \
		${SETENV} ${MAKE_ENV} ${MAKE_PROGRAM} \
		DESTDIR=${DESTDIR} install-permissions
	${INSTALL_DATA} ${WRKDIR}/mailer.conf ${DESTDIR}${EGDIR}
	${INSTALL_DATA} ${WRKDIR}/locallowercase \
		${DESTDIR}${EGDIR}/locallowercase

.include "../../mk/bsd.pkg.mk"
