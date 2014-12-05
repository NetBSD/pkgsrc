# $NetBSD: Makefile,v 1.1 2014/12/05 18:35:39 rodent Exp $

DISTNAME=	validate-email-address-1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	mail python
MASTER_SITES=	https://pypi.python.org/packages/source/v/validate-email-address/

MAINTAINER=	rodent@NetBSD.org
HOMEPAGE=	http://github.com/heropunch/validate-email-address
COMMENT=	Verify if an email address is valid and really exists
LICENSE=	gnu-lgpl-v3

USE_LANGUAGES=	# none

EGG_NAME=	${DISTNAME:S/-/_/1:S/-/_/1}

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
