# $NetBSD: Makefile,v 1.3 2018/03/20 16:24:34 khorben Exp $

DISTNAME=	z3-solver-4.5.1.0.post2
PKGNAME=	${PYPKGPREFIX}-z3solver-4.5.1.0.post2
CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_PYPI:=z/z3-solver/}

MAINTAINER=	khorben@defora.org
HOMEPAGE=	https://pypi.python.org/pypi/z3-solver/
COMMENT=	Theorem prover from Microsoft Research
LICENSE=	mit

USE_LANGUAGES=	c c++

PYTHON_VERSIONS_ACCEPTED=	27

CONFLICTS+=	z3-[0-9]*

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
