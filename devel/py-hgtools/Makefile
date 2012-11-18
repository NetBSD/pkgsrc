# $NetBSD: Makefile,v 1.2 2012/11/18 02:25:37 asau Exp $
#

HGTVERS=	2.0.2
DISTNAME=	hgtools-${HGTVERS}
PKGNAME=	${PYPKGPREFIX}-hgtools-${HGTVERS}
CATEGORIES=	devel python
MASTER_SITES=	http://pypi.python.org/packages/source/h/hgtools/
EXTRACT_SUFX=	.zip

MAINTAINER=	imil@NetBSD.org
HOMEPAGE=	http://pypi.python.org/packages/source/h/hgtools/
COMMENT=	Classes and setuptools plugin for Mercurial repositories
LICENSE=	gnu-gpl-v1

USE_LANGUAGES=	# none

post-extract:
	cd ${WRKSRC} && ${CHMOD} ${SHAREMODE} hgtools.egg-info/*

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
