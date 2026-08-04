# $NetBSD: Makefile,v 1.57 2026/08/04 20:28:56 wiz Exp $

DISTNAME=		onscripter-20230825
PKGREVISION=		3
CATEGORIES=		games
MASTER_SITES=		${MASTER_SITE_GITHUB:=ogapee/}
GITHUB_PROJECT=		${PKGBASE}
# XXX: YYYYMMDD format tag seems mis-recognized as a hash by fetch/github.mk
GITHUB_TAG=		refs/tags/${PKGVERSION_NOREV}

MAINTAINER=		tsutsui@NetBSD.org
HOMEPAGE=		https://ogapee.github.io/www/onscripter_en.html
COMMENT=		Interpreter to execute a script for NScripter
LICENSE=		gnu-gpl-v2

USE_LANGUAGES=	c++

INSTALLATION_DIRS=	bin \
			share/doc/onscripter

MAKE_FILE=	Makefile.Linux
BUILD_TARGET=	ALL

USE_TOOLS+=	pkg-config

WRKSRC=		${WRKDIR}/${DISTNAME}

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

# FIXME: replace by proper LDFLAGS handling
_WRAP_EXTRA_ARGS.CC+=	${_RELRO_LDFLAGS}
_WRAP_EXTRA_ARGS.CXX+=	${_RELRO_LDFLAGS}
CWRAPPERS_PREPEND.cc+=	${_RELRO_LDFLAGS}
CWRAPPERS_PREPEND.cxx+=	${_RELRO_LDFLAGS}

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
