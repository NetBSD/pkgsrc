# $NetBSD: Makefile,v 1.16 2008/01/24 11:10:53 tnn Exp $
#

DISTNAME=	${PKGNAME_NOREV}-src
PKGNAME=	hydra-5.3
PKGREVISION=	1
CATEGORIES=	security
MASTER_SITES=	http://freeworld.thc.org/releases/

MAINTAINER=	adrianp@NetBSD.org
HOMEPAGE=	http://freeworld.thc.org/thc-hydra/
COMMENT=	Login password cracker

.include "../../mk/bsd.prefs.mk"

USE_TOOLS+=	pkg-config
GNU_CONFIGURE=	YES
BUILD_TARGET=	all
WRKSRC=		${WRKDIR}/${DISTNAME}

LICENSE=	hydra-license

SUBST_CLASSES+=		build
SUBST_STAGE.build=	post-patch
SUBST_FILES.build=	Makefile.am configure hydra-gtk/src/main.c
SUBST_SED.build=	-e "s|@SSLBASE@|${BUILDLINK_PREFIX.openssl}|g"
SUBST_SED.build+=	-e "s|@PREFIX@|${PREFIX}|g"
SUBST_SED.build+=	-e "s|uname|${UNAME}|g"
SUBST_SED.build+=	-e "s|\\./hydra|${PREFIX}/bin/hydra|g"
SUBST_SED.build+=	-e "s|LIBS=-lm|LIBS=-lm ${COMPILER_RPATH_FLAG}${PREFIX}/lib ${COMPILER_RPATH_FLAG}/usr/lib|g"
SUBST_MESSAGE.build=	Patching build files.

USE_OLD_DES_API=	YES
PLIST_SRC=		${WRKDIR}/.PLIST_SRC
CONFIGURE_ARGS+=	--prefix=${PREFIX:Q}
BUILDLINK_API_DEPENDS.libssh+=	libssh-0.11{,nb*}

INSTALLATION_DIRS=	bin

.include "options.mk"

.include "../../security/openssl/buildlink3.mk"
.include "../../security/libssh/buildlink3.mk"

pre-build:
	${CP} ${PKGDIR}/PLIST ${WRKDIR}/.PLIST_SRC

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/hydra ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/pw-inspector ${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
