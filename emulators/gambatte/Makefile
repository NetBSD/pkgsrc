# $NetBSD: Makefile,v 1.32 2024/04/19 12:04:22 nia Exp $

DISTNAME=	gambatte_src-r571
PKGNAME=	${DISTNAME:S/_src-r/-/1}
CATEGORIES=	emulators
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=gambatte/files/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://emulation.gametechwiki.com/index.php/Gambatte
COMMENT=	Game Boy Color emulator with high accuracy
LICENSE=	gnu-gpl-v2

USE_LANGUAGES=	c c++

BUILD_DIRS+=	libgambatte gambatte_sdl

MKPIE_SUPPORTED=	no

SCONS_DO_INSTALL=	no

MAKE_ENV+=		LINKFLAGS=${LDFLAGS:Q}

SUBST_CLASSES+=		paths
SUBST_STAGE.paths=	pre-configure
SUBST_FILES.paths+=	gambatte_sdl/SConstruct
SUBST_VARS.paths+=	PREFIX

INSTALLATION_DIRS+=	bin
INSTALLATION_DIRS+=	${PKGMANDIR}/man1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/gambatte_sdl/gambatte_sdl \
		${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA} ${FILESDIR}/gambatte_sdl.1 \
		${DESTDIR}${PREFIX}/${PKGMANDIR}/man1

.include "../../devel/scons4/build.mk"
.include "../../devel/SDL/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
