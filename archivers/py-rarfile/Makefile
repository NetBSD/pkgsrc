# $NetBSD: Makefile,v 1.2 2019/09/16 08:56:17 adam Exp $

DISTNAME=	rarfile-3.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	archivers python
MASTER_SITES=	${MASTER_SITE_PYPI:=r/rarfile/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/markokr/rarfile
COMMENT=	RAR archive reader for Python
LICENSE=	isc

DEPENDS+=	bsdtar-[0-9]*:../../archivers/bsdtar

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
