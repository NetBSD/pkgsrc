# $NetBSD: Makefile,v 1.1 2021/02/25 15:23:21 khorben Exp $

DISTNAME=	sarge-0.1.6
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=s/sarge/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://bitbucket.org/vinay.sajip/sarge/
COMMENT=	Wrapper for subprocess which provides command pipeline functionality
LICENSE=	modified-bsd

USE_LANGUAGES=	# none

.include "../../lang/python/application.mk"
.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
