# $NetBSD: Makefile,v 1.21 2009/08/21 08:30:30 wiz Exp $
#

DISTNAME=		meld-1.3.1
CATEGORIES=		devel
MASTER_SITES=		${MASTER_SITE_GNOME:=sources/meld/1.3/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		dieter.NetBSD@pandora.be
HOMEPAGE=		http://meld.sourceforge.net/
COMMENT=		Visual diff and merge tool
LICENSE=		gnu-gpl-v2

DEPENDS+=		${PYPKGPREFIX}-gtk2>=2.8.0:../../x11/py-gtk2

PKG_DESTDIR_SUPPORT=	user-destdir

USE_PKGLOCALEDIR=		YES
USE_TOOLS+=			gmake msgfmt intltool
MAKE_FLAGS+=			prefix=${PREFIX}
MAKE_FLAGS+=			localedir=${PREFIX}/${PKGLOCALEDIR}/locale
MAKE_FLAGS+=			PYTHON=${PYTHONBIN}
MAKE_FILE=			GNUmakefile
PYTHON_PATCH_SCRIPTS=		meld
PYTHON_VERSIONS_INCOMPATIBLE=	23

# remove unnecessarily created empty dir
post-install:
	${RMDIR} ${DESTDIR}${PREFIX}/share/doc/meld

.include "../../lang/python/application.mk"
.include "../../mk/omf-scrollkeeper.mk"
.include "../../mk/bsd.pkg.mk"
