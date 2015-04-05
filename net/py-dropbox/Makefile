# $NetBSD: Makefile,v 1.5 2015/04/05 22:07:31 hiramatsu Exp $

DISTNAME=	dropbox-python-sdk-2.2.0
PKGNAME=	${PYPKGPREFIX}-dropbox-2.2.0
CATEGORIES=	net
MASTER_SITES=   https://www.dropbox.com/developers/downloads/sdks/core/python/
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
