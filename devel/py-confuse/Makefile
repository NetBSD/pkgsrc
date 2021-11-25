# $NetBSD: Makefile,v 1.1 2021/11/25 19:33:58 bsiegert Exp $

DISTNAME=	confuse-1.6.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	https://files.pythonhosted.org/packages/db/ec/fd93d96a32f54a3e19124179e86cced96da590d946c739a599f26d775a5f/

MAINTAINER=	bsiegert@NetBSD.org
HOMEPAGE=	https://github.com/beetbox/confuse
COMMENT=	Painless YAML configuration
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-yaml-[0-9]*:../../textproc/py-yaml

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
