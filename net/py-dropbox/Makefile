# $NetBSD: Makefile,v 1.4 2013/11/30 09:40:00 wiz Exp $

DISTNAME=	dropbox-python-sdk-1.6
PKGNAME=	${PYPKGPREFIX}-dropbox-1.6
PKGREVISION=	1
CATEGORIES=	net
MASTER_SITES=	https://www.dropbox.com/static/developers/
EXTRACT_SUFX=	.zip

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.dropbox.com/developers/core/sdks/python
COMMENT=	Dropbox Python API
LICENSE=	2-clause-bsd

EGG_NAME=	${DISTNAME:S/python-sdk-//}

USE_LANGUAGES=	# none
REPLACE_PYTHON=	tests/test_client.py

.include "../../lang/python/application.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
