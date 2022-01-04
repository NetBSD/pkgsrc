# $NetBSD: Makefile,v 1.5 2022/01/04 20:54:18 wiz Exp $

DISTNAME=	z3-solver-4.8.9.0
PKGNAME=	${PYPKGPREFIX}-z3solver-4.8.9.0
PKGREVISION=	1
CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_PYPI:=z/z3-solver/}

MAINTAINER=	khorben@defora.org
HOMEPAGE=	https://pypi.python.org/pypi/z3-solver/
COMMENT=	Theorem prover from Microsoft Research
LICENSE=	mit

USE_LANGUAGES=	c c++

CONFLICTS+=	z3-[0-9]*

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
