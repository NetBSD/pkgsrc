# $NetBSD: Makefile,v 1.133 2020/04/12 08:28:35 adam Exp $
#
# changelog at http://www.texmacs.org/tmweb/about/changes.en.html

DISTNAME=		TeXmacs-1.99.11-src
PKGNAME=		${DISTNAME:S/-src//}
PKGREVISION=		4
CATEGORIES=		editors
MASTER_SITES=		ftp://ftp.texmacs.org/pub/TeXmacs/tmftp/source/
MASTER_SITES+=		http://www.texmacs.org/Download/ftp/tmftp/source/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.texmacs.org/
COMMENT=		GNU TeXmacs (free scientific text editor)

DEPENDS+=		ps2pkm>=1.5:../../fonts/ps2pkm

#BUILD_TARGET=		TEXMACS

USE_CMAKE=		yes
USE_TOOLS+=		gmake perl:run pkg-config bash
USE_LANGUAGES=		c c++

REPLACE_PYTHON=		plugins/python/bin/tm_python
REPLACE_PYTHON+=	plugins/sage/bin/tm_sage
REPLACE_PYTHON+=	plugins/mathematica/bin/realpath.py

REPLACE_BASH+=		plugins/dratex/bin/tm_dratex
REPLACE_BASH+=		plugins/eukleides/bin/tm_eukleides
REPLACE_BASH+=		plugins/eukleides/bin/tm_eukleides.old
REPLACE_BASH+=		plugins/mupad/bin/tm_mupad_help
REPLACE_BASH+=		plugins/texgraph/bin/tm_texgraph

REPLACE_PERL+=		plugins/feynmf/bin/bbox_add.pl

SUBST_CLASSES+=		init
SUBST_STAGE.init=	pre-configure
SUBST_FILES.init=	plugins/python/progs/init-python.scm
SUBST_VARS.init=	PYTHONBIN

SUBST_CLASSES+=		guile
SUBST_STAGE.guile=	pre-configure
SUBST_FILES.guile=	cmake/FindGuile.cmake
SUBST_VARS.guile=	PREFIX

SUBST_CLASSES+=	bash
SUBST_SED.bash+=	-e "s,/bin/bash,${PREFIX}/bin/bash,"
SUBST_FILES.bash+=	src/Texmacs/Texmacs/texmacs.cpp
SUBST_MESSAGE.bash=	Fixing hardcoded bash path.
SUBST_STAGE.bash=	pre-configure

LDFLAGS+=	${COMPILER_RPATH_FLAG}${PREFIX}/guile/1.8/lib/

# do not install cmake files
post-install:
	${FIND} ${DESTDIR} -name cmake_install.cmake -type f | ${XARGS} ${RM} -f
	${FIND} ${DESTDIR} -name CMakeFiles -type d | ${XARGS} ${RM} -rf

.include "../../converters/libiconv/buildlink3.mk"
.include "../../databases/shared-mime-info/mimedb.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../graphics/gnome-icon-theme/buildlink3.mk"
.include "../../lang/guile/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../print/ghostscript/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
