# $NetBSD: Makefile,v 1.25 2016/03/05 11:29:18 jperkin Exp $
#

DISTNAME=	amap-5.2
PKGREVISION=	6
CATEGORIES=	net security
MASTER_SITES=	http://freeworld.thc.org/releases/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://freeworld.thc.org/thc-amap/
COMMENT=	Applications and Services scanner
LICENSE=	amap-license

HAS_CONFIGURE=	YES

CONFIGURE_ARGS+=	--prefix=${PREFIX:Q}
EGDIR=			${PREFIX}/share/examples/amap
PKG_SYSCONFSUBDIR?=	amap

CONF_FILES=	${EGDIR}/appdefs.resp ${PKG_SYSCONFDIR}/appdefs.resp
CONF_FILES+=	${EGDIR}/appdefs.rpc ${PKG_SYSCONFDIR}/appdefs.rpc
CONF_FILES+=	${EGDIR}/appdefs.trig ${PKG_SYSCONFDIR}/appdefs.trig

SUBST_CLASSES+=		conf
SUBST_FILES.conf=	configure
SUBST_STAGE.conf=	pre-configure
SUBST_SED.conf=		-e 's|@PREFIX@|${PREFIX}|g'
SUBST_SED.conf+=	-e 's|@MANDIR@|${PREFIX}/man|g'
SUBST_SED.conf+=	-e 's|@COMPILER_RPATH_FLAG@|${COMPILER_RPATH_FLAG}|g'
SUBST_SED.conf+=	-e 's|@SSLBASE@|${BUILDLINK_PREFIX.openssl}|g'
SUBST_SED.conf+=	-e "s|@UNAME@|${UNAME}|g"
SUBST_SED.conf+=	-e "s|@GREP@|${GREP}|g"
SUBST_SED.conf+=	-e "s|@SED@|${SED}|g"
SUBST_MESSAGE.conf=	Fixing configure script.

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1 ${EGDIR}

post-extract:
	${CHMOD} 0700 ${WRKSRC}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/amap ${DESTDIR}${PREFIX}/bin
	${LN} -s amap ${DESTDIR}${PREFIX}/bin/amap6
	${INSTALL_PROGRAM} ${WRKSRC}/amapcrap ${DESTDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/amap.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1
	${INSTALL_DATA} ${WRKSRC}/appdefs.trig ${DESTDIR}${EGDIR}
	${INSTALL_DATA} ${WRKSRC}/appdefs.resp ${DESTDIR}${EGDIR}
	${INSTALL_DATA} ${WRKSRC}/appdefs.rpc ${DESTDIR}${EGDIR}

.include "../../devel/pcre/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
