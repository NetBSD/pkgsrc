# $NetBSD: Makefile,v 1.2 2013/11/26 23:25:36 agc Exp $

DISTNAME=	dropbox-python-sdk-1.6
PKGNAME=	${PYPKGPREFIX}-dropbox-1.6
CATEGORIES=	net
MASTER_SITES=	https://www.dropbox.com/static/developers/
EXTRACT_SUFX=	.zip

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.dropbox.com/developers/core/sdks/python
COMMENT=	Dropbox Python API
LICENSE=	2-clause-bsd

PLIST_SUBST+=	PYVERSSUFFIX=${PYVERSSUFFIX:Q}

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
