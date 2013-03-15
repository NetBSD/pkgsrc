# $NetBSD: Makefile,v 1.36 2013/03/15 22:00:57 wiz Exp $
#

DISTNAME=		meld-1.7.1
CATEGORIES=		devel
MASTER_SITES=		${MASTER_SITE_GNOME:=sources/meld/1.7/}
EXTRACT_SUFX=		.tar.xz

MAINTAINER=		dieter.NetBSD@pandora.be
HOMEPAGE=		http://meldmerge.org/
COMMENT=		Visual diff and merge tool
LICENSE=		gnu-gpl-v2

DEPENDS+=		${PYPKGPREFIX}-gtk2>=2.14.0:../../x11/py-gtk2

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
.include "../../databases/shared-mime-info/mimedb.mk"
.include "../../mk/omf-scrollkeeper.mk"
.include "../../mk/bsd.pkg.mk"
