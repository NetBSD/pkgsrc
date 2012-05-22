# $NetBSD: Makefile,v 1.4 2012/05/22 08:28:46 obache Exp $
#

VERS=			4.2.3
DISTNAME=		cx_Freeze-${VERS}
PKGNAME=		${PYPKGPREFIX}-cxfreeze-${VERS}
CATEGORIES=		devel
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=cx-freeze/}

MAINTAINER=		helgoman@users.sourceforge.net
HOMEPAGE=		http://cx-freeze.sourceforge.net/
COMMENT=		Freezing python scripts into executables
LICENSE=		python-software-foundation

PKG_DESTDIR_SUPPORT=	user-destdir

PYTHON_VERSIONS_INCLUDE_3X=	yes

USE_LANGUAGES=      	c c++

PLIST_SUBST+=		PYVERSSUFFIX=${PYVERSSUFFIX}

post-extract:
	${MV} ${WRKSRC}/cxfreeze ${WRKSRC}/cxfreeze${PYVERSSUFFIX}

.include "../../lang/python/application.mk"
.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
