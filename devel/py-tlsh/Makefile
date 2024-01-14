# $NetBSD: Makefile,v 1.3 2024/01/14 20:08:04 schmonz Exp $

DISTNAME=	py-tlsh-4.7.2
PKGNAME=	${DISTNAME:S/py-/${PYPKGPREFIX}-/}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/py-tlsh/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://pypi.org/project/py-tlsh/
COMMENT=	TLSH C++ extension for Python
LICENSE=	apache-2.0

USE_LANGUAGES=	c c++

.include "../../devel/tlsh/buildlink3.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
