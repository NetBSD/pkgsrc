# $NetBSD: Makefile,v 1.4 2022/01/04 20:52:31 wiz Exp $

DISTNAME=	rarfile-3.3
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
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
