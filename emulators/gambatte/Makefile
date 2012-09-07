# $NetBSD: Makefile,v 1.13 2012/09/07 19:16:33 adam Exp $
#

DISTNAME=	gambatte_src-0.4.1
PKGNAME=	${DISTNAME:S/_src//}
PKGREVISION=	10
CATEGORIES=	emulators
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=gambatte/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://gambatte.sourceforge.net/
COMMENT=	Game Boy Color emulator

BUILD_DEPENDS+=	scons-[0-9]*:../../devel/scons

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=	c c++
INSTALLATION_DIRS=	bin share/doc/gambatte

SUBST_CLASSES+=		sdl
SUBST_FILES.sdl=	gambatte_sdl/SConstruct
SUBST_MESSAGE.sdl=	Fixing path to sdl-config.
SUBST_SED.sdl=		-e "s,sdl-config,${LOCALBASE}/bin/sdl-config,"
SUBST_STAGE.sdl=	pre-build

.include "options.mk"

do-build:
	cd ${WRKSRC}/libgambatte && ${SETENV} ${MAKE_ENV} scons
	cd ${WRKSRC}/gambatte_sdl && ${SETENV} ${MAKE_ENV} scons

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/gambatte_sdl/gambatte_sdl \
		${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/README ${DESTDIR}${PREFIX}/share/doc/gambatte

.include "../../devel/SDL/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
