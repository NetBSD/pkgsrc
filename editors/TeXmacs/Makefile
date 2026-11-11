# $NetBSD: Makefile,v 1.188 2026/11/11 11:52:54 wiz Exp $
#
# changelog at http://www.texmacs.org/tmweb/about/changes.en.html

DISTNAME=		TeXmacs-2.1.5-src
PKGNAME=		${DISTNAME:S/-src//}
PKGREVISION=		1
CATEGORIES=		editors
MASTER_SITES=		ftp://ftp.texmacs.org/pub/TeXmacs/tmftp/source/
MASTER_SITES+=		http://www.texmacs.org/Download/ftp/tmftp/source/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://www.texmacs.org/tmweb/home/welcome.en.html
COMMENT=		GNU TeXmacs (free scientific text editor)
LICENSE=		gnu-gpl-v3

DEPENDS+=		ps2pkm>=1.5:../../fonts/ps2pkm

USE_TOOLS+=		gmake perl:run pkg-config bash:run
USE_LANGUAGES=		c c++
USE_CXX_FEATURES=	c++11

WRKSRC=			${WRKDIR}/${DISTNAME:S/-src/.15315/}

REPLACE_PYTHON+=	plugins/mathematica/bin/realpath.py
REPLACE_PYTHON+=	plugins/eukleides/python/tm_eukleides.py

REPLACE_BASH+=		configure
REPLACE_BASH+=		cmake/CreateBundle.sh.in
REPLACE_BASH+=		plugins/feynmf/bin/tm_feynmf
REPLACE_BASH+=		plugins/lisp/bin/tm_lisp
REPLACE_BASH+=		plugins/lush/bin/tm_lush
REPLACE_BASH+=		plugins/mathematica/bin/tm_mathematica
REPLACE_BASH+=		plugins/matlab/bin/tm_matlab
REPLACE_BASH+=		plugins/mupad/bin/tm_mupad
REPLACE_BASH+=		plugins/mupad/bin/tm_mupad_help
REPLACE_BASH+=		plugins/texgraph/bin/tm_texgraph

REPLACE_PERL+=		plugins/feynmf/bin/bbox_add.pl

SUBST_CLASSES+=		pyexec
SUBST_SED.pyexec+=	-e "s,python3,python${PYVERSSUFFIX},"
SUBST_FILES.pyexec+=	TeXmacs/progs/kernel/library/base.scm
SUBST_MESSAGE.pyexec=	Fixing name of python executable in ${SUBST_FILES.pyexec}
SUBST_STAGE.pyexec=	pre-configure

# xdg-open is executed by some of the menus
DEPENDS+=		xdg-utils-[0-9]*:../../misc/xdg-utils

.include "options.mk"

.include "../../devel/cmake/build.mk"

.include "../../converters/libiconv/buildlink3.mk"
.include "../../databases/shared-mime-info/mimedb.mk"
.include "../../databases/sqlite3/buildlink3.mk"
.include "../../devel/gmp/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../graphics/gnome-icon-theme/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
# Builds with guile20 but crashes with it
# Building with guile22 of guile30 fails (apparent use of withdrawn interfaces).
.include "../../lang/guile18/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../print/ghostscript/buildlink3.mk"
.include "../../security/gnutls/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/jpeg.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
