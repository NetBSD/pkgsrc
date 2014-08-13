# $NetBSD: Makefile,v 1.8 2014/08/13 22:39:30 joerg Exp $

SVN_REVISION=	1949
DIST_VERSION=	0.1
DISTNAME=	gyp-${DIST_VERSION}pre${SVN_REVISION}
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_LOCAL}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://code.google.com/p/gyp/
COMMENT=	GYP can Generate Your Projects
LICENSE=	modified-bsd

PYTHON_VERSIONS_INCOMPATIBLE=  26 33 34 # not yet ported as of 0.1pre1718
EGG_NAME=	gyp-${DIST_VERSION}

# for test
USE_TOOLS+=	gmake
USE_LANGUAGES=	c c++

do-test:
	${RUN}cd ${WRKSRC}; LANG=C ${SETENV} ${TEST_ENV} ${PYTHONBIN} gyptest.py -a -f make --passed

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
