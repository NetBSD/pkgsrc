# $NetBSD: Makefile,v 1.11 2008/02/19 13:23:06 adrianp Exp $

DISTNAME=	dkim-milter-2.4.4
CATEGORIES=	mail
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=dkim-milter/}

MAINTAINER=	imil@gcu.info
HOMEPAGE=	http://sourceforge.net/projects/dkim-milter/
COMMENT=	Open source DKIM filter software from Sendmail, Inc

BUILDLINK_API_DEPENDS.libmilter+=	libmilter>=8.13.0
BUILDLINK_API_DEPENDS.openssl+=		openssl>=0.9.8

LICENSE=		sendmail-open-source-license

MAKE_ENV+=		M4=${M4:Q}
RCD_SCRIPTS=		dkim-filter
USE_BUILTIN.libmilter=	no
USE_TOOLS+=		gm4
PKG_OPTIONS_VAR=	PKG_OPTIONS.dkim-milter
PKG_SUPPORTED_OPTIONS=	inet6
EGDIR=			${PREFIX}/share/examples/dkim-milter
FILES_SUBST+=		DKIM_USER=${DKIM_USER:Q} DKIM_GROUP=${DKIM_GROUP:Q}
BUILD_DEFS+=		VARBASE DKIM_USER DKIM_GROUP

DKIM_USER?=		dkim
DKIM_GROUP?=		dkim
PKG_GROUPS=		${DKIM_USER}
PKG_USERS=		${DKIM_USER}:${DKIM_GROUP}
PKG_GROUPS_VARS+=	DKIM_GROUP
PKG_USERS_VARS+=	DKIM_USER
OWN_DIRS_PERMS+=	${VARBASE}/run/dkim-filter \
			${DKIM_USER} ${DKIM_GROUP} 0750

.include "../../mk/bsd.options.mk"

SUBST_CLASSES+=		libs
SUBST_STAGE.libs=	pre-configure
SUBST_FILES.libs=	${WRKSRC}/devtools/Site/site.config.m4
SUBST_FILES.libs+=	dkim-filter/dkim-filter.conf.5 dkim-filter/dkim-stats.8
SUBST_SED.libs=		-e 's|@SSLBASE@|${BUILDLINK_PREFIX.openssl}|g'
SUBST_SED.libs+=	-e 's|@LMBASE@|${BUILDLINK_PREFIX.libmilter}|g'
SUBST_SED.libs+=	-e 's|@PTHREAD@|${BUILDLINK_PREFIX.pthread}|g'
SUBST_SED.libs+=	-e 's|@PTHREAD_LDFLAGS@|${PTHREAD_LDFLAGS} ${PTHREAD_LIBS}|g'
SUBST_SED.libs+=	-e 's|@PREFIX@|${PREFIX}|g'
SUBST_SED.libs+=	-e 's|@PKGMANDIR@|${PKGMANDIR}|g'
SUBST_SED.libs+=	-e 's|/etc/mail|${PKG_SYSCONFDIR}|g'
SUBST_SED.libs+=	-e 's|.I /etc/dkim-filter.conf|.I ${PKG_SYSCONFDIR}/dkim-filter.conf|g'
.if !empty(PKG_OPTIONS:Minet6)
SUBST_SED.libs+=	-e 's|@INET6@||'
.else
SUBST_SED.libs+=	-e 's|@INET6@|dnl|'
.endif
SUBST_MESSAGE.libs=	Fixing Makefile references and man pages.

CONF_FILES=		${EGDIR}/dkim-filter.conf.sample \
			${PKG_SYSCONFDIR}/dkim-filter.conf

INSTALLATION_DIRS=	share/doc/dkim-milter ${EGDIR}

post-extract:
	${CP} ${WRKSRC}/site.config.m4.dist \
		${WRKSRC}/devtools/Site/site.config.m4

do-build:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ./Build

do-install:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ./Build install

post-install:
	${INSTALL_DATA} ${WRKSRC}/dkim-filter/dkim-filter.conf.sample ${EGDIR}
	${INSTALL_DATA} ${WRKSRC}/FEATURES ${PREFIX}/share/doc/dkim-milter
	${INSTALL_DATA} ${WRKSRC}/INSTALL ${PREFIX}/share/doc/dkim-milter
	${INSTALL_DATA} ${WRKSRC}/KNOWNBUGS ${PREFIX}/share/doc/dkim-milter
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/dkim-milter
	${INSTALL_DATA} ${WRKSRC}/RELEASE_NOTES ${PREFIX}/share/doc/dkim-milter

.include "../../security/openssl/buildlink3.mk"
.include "../../mail/libmilter/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
