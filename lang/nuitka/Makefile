# $NetBSD: Makefile,v 1.7 2022/01/10 20:22:58 wiz Exp $

DISTNAME=	Nuitka-0.5.0.1
PKGNAME=	${DISTNAME:C/N/n/}
PKGREVISION=	4
CATEGORIES=	lang
MASTER_SITES=	http://nuitka.net/releases/

MAINTAINER=	agc@NetBSD.org
HOMEPAGE=	https://www.nuitka.net/pages/overview.html
COMMENT=	Python to C++ compiler
LICENSE=	apache-2.0

# included scons is not ready for python 3.x
PYTHON_VERSIONS_ACCEPTED=	27

REPLACE_PYTHON+=	misc/check-release
REPLACE_PYTHON+=	misc/check-with-pylint
REPLACE_PYTHON+=	bin/nuitka-run
REPLACE_PYTHON+=	bin/nuitka
REPLACE_PYTHON+=	bin/compare_with_cpython
REPLACE_PYTHON+=	bin/compare_with_xml
REPLACE_PYTHON+=	tests/benchmarks/pybench/clockres.py
REPLACE_PYTHON+=	tests/benchmarks/pybench/Setup.py
REPLACE_PYTHON+=	tests/benchmarks/pybench/systimes.py
REPLACE_PYTHON+=	tests/benchmarks/comparisons/GeneratorFunctionVsGeneratorExpression.py
REPLACE_PYTHON+=	tests/benchmarks/pystone.py
REPLACE_PYTHON+=	tests/packages/run_all.py
REPLACE_PYTHON+=	tests/standalone/run_all.py
REPLACE_PYTHON+=	tests/syntax/run_all.py
REPLACE_PYTHON+=	tests/reflected/compile_itself.py
REPLACE_PYTHON+=	tests/basics/run_xml.py
REPLACE_PYTHON+=	tests/basics/run_all.py
REPLACE_PYTHON+=	tests/programs/run_all.py
REPLACE_PYTHON+=	nuitka/build/inline_copy/bin/scons.py

.include "../../lang/python/application.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
