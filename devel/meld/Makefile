# $NetBSD: Makefile,v 1.8 2008/04/25 20:39:08 joerg Exp $
#

DISTNAME=		meld-1.1.5.1
PKGREVISION=		1
CATEGORIES=		devel
MASTER_SITES=		http://ftp.gnome.org/pub/gnome/sources/meld/1.1/
EXTRACT_SUFX=		.tar.bz2

DEPENDS+=		${PYPKGPREFIX}-gtk2>=2.6.0:../../x11/py-gtk2
DEPENDS+=		${PYPKGPREFIX}-gnome2>=2.6.0:../../x11/py-gnome2

MAINTAINER=		dieter.NetBSD@pandora.be
HOMEPAGE=		http://meld.sourceforge.net/
COMMENT=		Visual diff and merge tool

USE_DIRS+=			xdg-1.3
USE_DIRS+=			gnome2-1.6
USE_PKGLOCALEDIR=		YES
USE_TOOLS+=			gmake msgfmt intltool
MAKE_FLAGS+=			prefix=${PREFIX}
MAKE_FLAGS+=			localedir=${PREFIX}/${PKGLOCALEDIR}
MAKE_FLAGS+=			PYTHON=${PYTHONBIN}
MAKE_FILE=			GNUmakefile
PYTHON_PATCH_SCRIPTS=		meld

.include "../../lang/python/application.mk"
.include "../../textproc/scrollkeeper/omf.mk"
.include "../../mk/bsd.pkg.mk"
