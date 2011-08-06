# $NetBSD: Makefile,v 1.28 2011/08/06 10:45:21 wiz Exp $
#

DISTNAME=		meld-1.5.2
CATEGORIES=		devel
MASTER_SITES=		${MASTER_SITE_GNOME:=sources/meld/1.5/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		dieter.NetBSD@pandora.be
HOMEPAGE=		http://meld.sourceforge.net/
COMMENT=		Visual diff and merge tool
LICENSE=		gnu-gpl-v2

DEPENDS+=		${PYPKGPREFIX}-gtk2>=2.14.0:../../x11/py-gtk2

PKG_DESTDIR_SUPPORT=	user-destdir

PYTHON_VERSIONS_INCOMPATIBLE=	24

USE_PKGLOCALEDIR=		YES
USE_TOOLS+=			gmake msgfmt intltool
MAKE_FLAGS+=			prefix=${PREFIX}
MAKE_FLAGS+=			localedir=${PREFIX}/${PKGLOCALEDIR}/locale
MAKE_FLAGS+=			PYTHON=${PYTHONBIN}
PYTHON_PATCH_SCRIPTS=		bin/meld

# remove unnecessarily created empty dirs
post-install:
	${RMDIR} ${DESTDIR}${PREFIX}/share/doc/meld
	${RMDIR} ${DESTDIR}${PREFIX}/share/pixmaps

.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../lang/python/application.mk"
.include "../../mk/omf-scrollkeeper.mk"
.include "../../mk/bsd.pkg.mk"
