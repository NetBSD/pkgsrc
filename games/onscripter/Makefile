# $NetBSD: Makefile,v 1.15 2012/09/07 15:02:44 tsutsui Exp $
#

DISTNAME=		onscripter-20120901
CATEGORIES=		games
MASTER_SITES=		http://onscripter.sourceforge.jp/

MAINTAINER=		tsutsui@NetBSD.org
HOMEPAGE=		http://onscripter.sourceforge.jp/onscripter.html
COMMENT=		Interpreter to execute a script for NScripter
LICENSE=		gnu-gpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=	c++

INSTALLATION_DIRS=	bin \
			share/doc/onscripter

MAKE_FILE=	Makefile.Linux
BUILD_TARGET=	ALL

USE_TOOLS+=	pkg-config

SUBST_CLASSES+=		fix
SUBST_STAGE.fix=	pre-configure
SUBST_FILES.fix=	${MAKE_FILE}
SUBST_SED.fix=		-e 's!@RM@!${RM}!g'
SUBST_SED.fix+=		-e 's!@CXX@!${CXX:Q}!g'
SUBST_SED.fix+=		-e 's!@LD@!${LD:Q}!g'
SUBST_SED.fix+=		-e 's!@CXXFLAGS@!${CXXFLAGS:Q}!g'

do-install:
.for f in nsaconv nsadec onscripter sarconv sardec
	${INSTALL_PROGRAM} ${WRKSRC}/${f} ${DESTDIR}${PREFIX}/bin
.endfor
.for f in ogapee.css onscripter.html
	${INSTALL_DATA} ${WRKSRC}/www/${f} ${DESTDIR}${PREFIX}/share/doc/${PKGBASE}
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
