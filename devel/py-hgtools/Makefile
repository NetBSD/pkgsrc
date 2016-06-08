# $NetBSD: Makefile,v 1.5 2016/06/08 17:43:25 wiz Exp $

HGTVERS=	6.3
DISTNAME=	hgtools-${HGTVERS}
PKGNAME=	${PYPKGPREFIX}-hgtools-${HGTVERS}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=h/hgtools/}
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
