# $NetBSD: Makefile,v 1.2 2005/06/17 03:50:31 jlam Exp $
#

DISTNAME=       amap-5.0
CATEGORIES=     net security
MASTER_SITES=   http://www.thc.org/releases/

MAINTAINER=     adam@monkeybyte.org
HOMEPAGE=       http://www.thc.org/
COMMENT=        Applications and Services scanner

HAS_CONFIGURE=	YES
USE_PKGINSTALL=	YES

CONFIGURE_ARGS+=	--prefix=${PREFIX}
EGDIR=			${PREFIX}/share/examples/amap
PKG_SYSCONFSUBDIR?=	amap

LICENSE+=	amap-license

CONF_FILES=	${EGDIR}/appdefs.resp ${PKG_SYSCONFDIR}/appdefs.resp
CONF_FILES+=	${EGDIR}/appdefs.rpc ${PKG_SYSCONFDIR}/appdefs.rpc
CONF_FILES+=	${EGDIR}/appdefs.trig ${PKG_SYSCONFDIR}/appdefs.trig

SUBST_CLASSES=		conf
SUBST_FILES.conf=	configure
SUBST_STAGE.conf=	pre-configure
SUBST_SED.conf=		-e 's|@PREFIX@|${PREFIX}|g' \
			-e 's|@MANDIR@|${PREFIX}/man|g' \
			-e 's|@COMPILER_RPATH_FLAG@|${COMPILER_RPATH_FLAG}|g' \
			-e 's|@SSLBASE@|${BUILDLINK_PREFIX.openssl}|g' \
			-e "s|@UNAME@|${UNAME}|g"
SUBST_MESSAGE.conf=	"Fixing configure script."

INSTALLATION_DIRS=	bni man/man1

.include "../../security/openssl/buildlink3.mk"

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

.include "../../mk/bsd.pkg.mk"
