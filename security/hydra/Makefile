# $NetBSD: Makefile,v 1.2 2005/06/17 03:50:32 jlam Exp $
#

DISTNAME=	${PKGNAME}-src
PKGNAME=	hydra-4.6
CATEGORIES=	security
MASTER_SITES=	http://www.thc.org/releases/

MAINTAINER=	adrianp@NetBSD.org
HOMEPAGE=	http://www.thc.org/thc-hydra/
COMMENT=	Login password cracker

.include "../../mk/bsd.prefs.mk"

GNU_CONFIGURE=	YES
BUILD_TARGET=	all ssl
WRKSRC=		${WRKDIR}/${DISTNAME}

LICENSE+=	hydra-license

SUBST_CLASSES=		build
SUBST_STAGE.build=	post-patch
SUBST_FILES.build=	Makefile.am configure hydra-gtk/src/main.c
SUBST_SED.build=	-e "s|@SSLBASE@|${BUILDLINK_PREFIX.openssl}|g" \
			-e "s|@PREFIX@|${PREFIX}|g" \
			-e "s|uname|${UNAME}|g" \
			-e "s|\./hydra|${PREFIX}/bin/hydra|g" \
			-e "s|LIBS=-lm|LIBS=-lm ${COMPILER_RPATH_FLAG}${PREFIX}/lib ${COMPILER_RPATH_FLAG}/usr/lib|g"
SUBST_MESSAGE.build=	"Patching build files."

USE_OLD_DES_API=	YES
PLIST_SRC=		${WRKDIR}/.PLIST_SRC
CONFIGURE_ARGS+=	--prefix=${PREFIX}
BUILDLINK_DEPENDS.libssh+=	libssh-0.1

INSTALLATION_DIRS=	bin

PKG_OPTIONS_VAR=	PKG_OPTIONS.hydra
PKG_SUPPORTED_OPTIONS=	gtkfe

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mgtkfe)

.include "../../devel/pkgconfig/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"

post-configure:
	cd ${WRKSRC}/hydra-gtk && \
	${SETENV} ${CONFIGURE_ENV} ${CONFIGURE_SCRIPT} ${CONFIGURE_ARGS}

post-build:
	cd ${WRKSRC}/hydra-gtk && \
	${SETENV} ${MAKE_ENV} ${MAKE_PROGRAM}

post-install:
	${INSTALL_PROGRAM} ${WRKSRC}/hydra-gtk/src/xhydra ${PREFIX}/bin

PLIST_SRC+=	${PKGDIR}/PLIST.xhydra
.endif

.include "../../security/openssl/buildlink3.mk"
.include "../../security/libssh/buildlink3.mk"

pre-build:
	 @${CP} ${PKGDIR}/PLIST ${WRKDIR}/.PLIST_SRC

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/hydra ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/pw-inspector ${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
