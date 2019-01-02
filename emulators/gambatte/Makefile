# $NetBSD: Makefile,v 1.30 2019/01/02 19:19:51 tnn Exp $
#

DISTNAME=	gambatte_src-0.4.1
PKGNAME=	${DISTNAME:S/_src//}
PKGREVISION=	23
CATEGORIES=	emulators
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=gambatte/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://gambatte.sourceforge.net/
COMMENT=	Game Boy Color emulator

USE_LANGUAGES=	c c++03
INSTALLATION_DIRS=	bin share/doc/gambatte

SUBST_CLASSES+=		sdl
SUBST_FILES.sdl=	gambatte_sdl/SConstruct
SUBST_MESSAGE.sdl=	Fixing path to sdl-config.
SUBST_SED.sdl=		-e "s,sdl-config,${LOCALBASE}/bin/sdl-config,"
SUBST_STAGE.sdl=	pre-build

.include "options.mk"

do-build:
	cd ${WRKSRC}/libgambatte && ${PKGSRC_SETENV} ${MAKE_ENV} ${SCONSBIN}
	cd ${WRKSRC}/gambatte_sdl && ${PKGSRC_SETENV} ${MAKE_ENV} ${SCONSBIN}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/gambatte_sdl/gambatte_sdl \
		${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/README ${DESTDIR}${PREFIX}/share/doc/gambatte

.include "../../devel/SDL/buildlink3.mk"
PYTHON_FOR_BUILD_ONLY?=	yes
.include "../../devel/scons/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
