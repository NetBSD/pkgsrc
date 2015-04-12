# $NetBSD: Makefile,v 1.4 2015/04/12 14:16:28 wiz Exp $

HGTVERS=	6.3
DISTNAME=	hgtools-${HGTVERS}
PKGNAME=	${PYPKGPREFIX}-hgtools-${HGTVERS}
CATEGORIES=	devel python
MASTER_SITES=	http://pypi.python.org/packages/source/h/hgtools/
EXTRACT_SUFX=	.zip

MAINTAINER=	imil@NetBSD.org
HOMEPAGE=	https://pypi.python.org/pypi/hgtools
COMMENT=	Classes and setuptools plugin for Mercurial and Git repositories
LICENSE=	mit

USE_LANGUAGES=	# none

post-extract:
	cd ${WRKSRC} && ${CHMOD} ${SHAREMODE} hgtools.egg-info/*

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
