# $NetBSD: Makefile,v 1.1 2013/01/18 11:32:45 ryoon Exp $

SVN_REVISION=	1559
DIST_VERSION=	0.1
DISTNAME=	gyp-${DIST_VERSION}pre${SVN_REVISION}
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_LOCAL}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	obache@NetBSD.org
HOMEPAGE=	http://code.google.com/p/gyp/
COMMENT=	GYP can Generate Your Projects
LICENSE=	modified-bsd

EGG_NAME=	gyp-${DIST_VERSION}

# for test
USE_TOOLS+=	gmake
USE_LANGUAGES=	c c++
do-test:
	${RUN}cd ${WRKSRC}; LANG=C ${SETENV} ${TEST_ENV} ${PYTHONBIN} gyptest.py -a -f make --passed

.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
