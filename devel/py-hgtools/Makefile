# $NetBSD: Makefile,v 1.1 2012/11/03 13:55:16 imil Exp $
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

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=	# none

post-extract:
	cd ${WRKSRC} && ${CHMOD} ${SHAREMODE} hgtools.egg-info/*

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
