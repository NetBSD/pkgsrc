# $NetBSD: Makefile,v 1.12 2008/11/24 14:03:56 wiz Exp $
#

DISTNAME=		meld-1.2.1
CATEGORIES=		devel
MASTER_SITES=		${MASTER_SITE_GNOME:=sources/meld/1.2/}
EXTRACT_SUFX=		.tar.bz2

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=		${PYPKGPREFIX}-gtk2>=2.8.0:../../x11/py-gtk2
DEPENDS+=		${PYPKGPREFIX}-gnome2>=2.6.0:../../x11/py-gnome2

MAINTAINER=		dieter.NetBSD@pandora.be
HOMEPAGE=		http://meld.sourceforge.net/
COMMENT=		Visual diff and merge tool

USE_DIRS+=			xdg-1.3
USE_DIRS+=			gnome2-1.6
USE_PKGLOCALEDIR=		YES
USE_TOOLS+=			gmake msgfmt intltool
MAKE_FLAGS+=			prefix=${PREFIX}
MAKE_FLAGS+=			localedir=${PREFIX}/${PKGLOCALEDIR}/locale
MAKE_FLAGS+=			PYTHON=${PYTHONBIN}
MAKE_FILE=			GNUmakefile
PYTHON_PATCH_SCRIPTS=		meld

post-extract:
	# msgfmt complains about this in 1.2.1
	${RM} ${WRKSRC}/po/sq.po

# remove unnecessarily created empty dir
post-install:
	${RMDIR} ${DESTDIR}${PREFIX}/share/doc/meld

.include "../../lang/python/application.mk"
.include "../../textproc/scrollkeeper/omf.mk"
.include "../../mk/bsd.pkg.mk"
