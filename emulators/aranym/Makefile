# $NetBSD: Makefile,v 1.47 2022/06/28 11:33:50 wiz Exp $

DISTNAME=	aranym_1.1.0.orig
PKGNAME=	${DISTNAME:S/_/-/:S/.orig//}
PKGREVISION=	8
CATEGORIES=	emulators
MASTER_SITES=	${MASTER_SITE_GITHUB:=aranym/}
GITHUB_PROJECT=	aranym
GITHUB_RELEASE=	ARANYM_1_1_0

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://aranym.github.io/
COMMENT=	Atari Running on Any Machine
LICENSE=	gnu-gpl-v2

ETVER=		0.9.11

SITES.emutos-512k-${ETVER}.zip= \
	${MASTER_SITE_SOURCEFORGE:=emutos/}

DISTFILES=	${DEFAULT_DISTFILES} emutos-512k-${ETVER}.zip

WRKSRC=		${WRKDIR}/${PKGNAME_NOREV}
USE_TOOLS+=	pkg-config perl
USE_LANGUAGES=	c c++
GNU_CONFIGURE=	yes
MANCOMPRESSED=	yes

CHECK_PORTABILITY_SKIP=	src/Unix/MacOSX/scripts/gen_machfiles.sh

CONFIGURE_ARGS+=	--enable-fullmmu
CONFIGURE_ARGS+=	--enable-atc=full
CONFIGURE_ARGS+=	--disable-sdltest

EMUTOS_WRKSRC=		${WRKDIR}/emutos-512k-${ETVER}
EMUTOS_DOC_DIR=		${PREFIX}/share/doc/aranym/emutos
EMUTOS_ROM_DIR=		${PREFIX}/share/aranym

REQD_DIRS+=		${EMUTOS_ROM_DIR} ${EMUTOS_DOC_DIR}

SUBST_CLASSES+=		paths
SUBST_STAGE.paths=	post-build
SUBST_FILES.paths=	doc/config
SUBST_FILES.paths+=	doc/aranym.1
SUBST_VARS.paths+=	PREFIX
SUBST_SED.paths+=	-e "s|/usr/share/|${PREFIX}/share/|g"
SUBST_MESSAGE.paths=	Setting path to PREFIX.

INSTALLATION_DIRS+=	${EMUTOS_DOC_DIR} ${EMUTOS_ROM_DIR}

post-install:
	${RM} -f ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/aranym-jit.1
	${RM} -f ${DESTDIR}${PREFIX}/share/applications/aranym.desktop
	${RM} -f ${DESTDIR}${PREFIX}/share/applications/aranym-jit.desktop
	${INSTALL_DATA} ${EMUTOS_WRKSRC}/etos512k.img ${DESTDIR}${EMUTOS_ROM_DIR}
	${INSTALL_DATA} ${EMUTOS_WRKSRC}/readme.txt ${DESTDIR}${EMUTOS_DOC_DIR}
	${INSTALL_DATA} ${EMUTOS_WRKSRC}/doc/announce.txt ${DESTDIR}${EMUTOS_DOC_DIR}
	${INSTALL_DATA} ${EMUTOS_WRKSRC}/doc/authors.txt ${DESTDIR}${EMUTOS_DOC_DIR}
	${INSTALL_DATA} ${EMUTOS_WRKSRC}/doc/changelog.txt ${DESTDIR}${EMUTOS_DOC_DIR}
	${INSTALL_DATA} ${EMUTOS_WRKSRC}/doc/license.txt ${DESTDIR}${EMUTOS_DOC_DIR}
	${INSTALL_DATA} ${EMUTOS_WRKSRC}/doc/status.txt ${DESTDIR}${EMUTOS_DOC_DIR}

.include "../../devel/SDL2/buildlink3.mk"
.include "../../mk/bsd.prefs.mk"
.if ${OPSYS} != "Darwin"
.  if !empty(PKG_BUILD_OPTIONS.SDL2:Mopengl)
.    include "../../graphics/glu/buildlink3.mk"
.  else
CONFIGURE_ARGS+=	--disable-opengl
.  endif
.endif
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../math/mpfr/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/jpeg.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
