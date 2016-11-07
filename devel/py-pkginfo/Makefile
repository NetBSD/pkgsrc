# $NetBSD: Makefile,v 1.4 2016/11/07 11:16:29 wiz Exp $

DISTNAME=	pkginfo-1.4.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pkginfo/}

MAINTAINER=	kamel.derouiche@gmail.com
HOMEPAGE=	http://pypi.python.org/pypi/pkginfo/
COMMENT=	Query metadatdata from sdists / bdists / installed packages
LICENSE=	mit

USE_LANGUAGES=	# none

# https://bugs.launchpad.net/pkginfo/+bug/1639585
pre-build:
	${TOUCH} ${WRKSRC}/CHANGES.txt

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
