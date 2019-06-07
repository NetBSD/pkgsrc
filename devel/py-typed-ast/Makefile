# $NetBSD: Makefile,v 1.9 2019/06/07 07:29:48 adam Exp $

DISTNAME=	typed_ast-1.4.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/_/-/}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=t/typed-ast/}

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	https://github.com/python/typed_ast
COMMENT=	Optional static typing for Python
LICENSE=	apache-2.0 AND python-software-foundation

PYTHON_VERSIONS_INCOMPATIBLE=	27

SUBST_CLASSES+=		fix-incl
SUBST_STAGE.fix-incl=	pre-configure
SUBST_MESSAGE.fix-incl=	Make includes more specific to avoid conflicts.
SUBST_FILES.fix-incl=	ast27/*/*.[ch]
SUBST_FILES.fix-incl+=	ast3/*/*.[ch]
.for f in Python-ast.h asdl.h ast.h bitset.h compile.h compile-ast3.h \
	errcode.h graminit.h grammar.h node.h parsetok.h token.h
SUBST_SED.fix-incl+=	-e 's,^\#include "${f}",\#include "Include/${f}",'
.endfor

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
