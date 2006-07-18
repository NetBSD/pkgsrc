# $NetBSD: Makefile,v 1.10 2006/07/18 22:12:30 adrianp Exp $
#

DISTNAME=       amap-5.0
PKGREVISION=	1
CATEGORIES=     net security
MASTER_SITES=   http://thc.segfault.net/releases/ \
		http://www.thc.org/releases/

MAINTAINER=     pkgsrc-users@NetBSD.org
HOMEPAGE=       http://thc.org.segfault.net/thc-amap/
COMMENT=        Applications and Services scanner

HAS_CONFIGURE=	YES

CONFIGURE_ARGS+=	--prefix=${PREFIX:Q}
EGDIR=			${PREFIX}/share/examples/amap
PKG_SYSCONFSUBDIR?=	amap

LICENSE+=	amap-license

CONF_FILES=	${EGDIR}/appdefs.resp ${PKG_SYSCONFDIR}/appdefs.resp
CONF_FILES+=	${EGDIR}/appdefs.rpc ${PKG_SYSCONFDIR}/appdefs.rpc
CONF_FILES+=	${EGDIR}/appdefs.trig ${PKG_SYSCONFDIR}/appdefs.trig

SUBST_CLASSES+=		conf
SUBST_FILES.conf=	configure
SUBST_STAGE.conf=	pre-configure
SUBST_SED.conf=		-e 's|@PREFIX@|${PREFIX}|g' \
			-e 's|@MANDIR@|${PREFIX}/man|g' \
			-e 's|@COMPILER_RPATH_FLAG@|${COMPILER_RPATH_FLAG}|g' \
			-e 's|@SSLBASE@|${BUILDLINK_PREFIX.openssl}|g' \
			-e "s|@UNAME@|${UNAME}|g"
SUBST_MESSAGE.conf=	Fixing configure script.

INSTALLATION_DIRS=	bni man/man1

post-extract:
	@${CHMOD} 0700 ${WRKSRC}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/amap ${PREFIX}/bin
	${LN} -s ${PREFIX}/bin/amap ${PREFIX}/bin/amap6
	${INSTALL_PROGRAM} ${WRKSRC}/amapcrap ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/amap.1 ${PREFIX}/man/man1
	${INSTALL_DATA_DIR} ${EGDIR}
	${INSTALL_DATA} ${WRKSRC}/appdefs.trig ${EGDIR}
	${INSTALL_DATA} ${WRKSRC}/appdefs.resp ${EGDIR}
	${INSTALL_DATA} ${WRKSRC}/appdefs.rpc ${EGDIR}


.include "../../devel/pcre/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
