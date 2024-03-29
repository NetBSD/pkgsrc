# $NetBSD: Makefile,v 1.50 2023/11/12 13:21:41 wiz Exp $
#

DISTNAME=		onscripter-20230825
PKGREVISION=		1
CATEGORIES=		games
MASTER_SITES=		https://onscripter.osdn.jp/

MAINTAINER=		tsutsui@NetBSD.org
HOMEPAGE=		https://onscripter.osdn.jp/onscripter.html
COMMENT=		Interpreter to execute a script for NScripter
LICENSE=		gnu-gpl-v2

USE_LANGUAGES=	c++

INSTALLATION_DIRS=	bin \
			share/doc/onscripter

MAKE_FILE=	Makefile.Linux
BUILD_TARGET=	ALL

USE_TOOLS+=	pkg-config

.include "options.mk"

SUBST_CLASSES+=		fix
SUBST_STAGE.fix=	pre-configure
SUBST_FILES.fix=	${MAKE_FILE}
SUBST_VARS.fix=		RM
SUBST_VARS.fix+=	CXX
SUBST_VARS.fix+=	LD
SUBST_VARS.fix+=	CXXFLAGS
SUBST_VARS.fix+=	PDA_DEFS

do-install:
.for f in nsaconv nsadec onscripter sarconv sardec
	${INSTALL_PROGRAM} ${WRKSRC}/${f} ${DESTDIR}${PREFIX}/bin
.endfor
	${INSTALL_DATA} ${WRKSRC}/README ${DESTDIR}${PREFIX}/share/doc/${PKGBASE}

.include "../../archivers/bzip2/buildlink3.mk"
.include "../../audio/libvorbis/buildlink3.mk"
.include "../../audio/SDL_mixer/buildlink3.mk"
.include "../../devel/SDL_ttf/buildlink3.mk"
.include "../../fonts/fontconfig/buildlink3.mk"
.include "../../lang/lua/buildlink3.mk"
.include "../../graphics/SDL_image/buildlink3.mk"
.include "../../multimedia/smpeg/buildlink3.mk"
.include "../../mk/jpeg.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
