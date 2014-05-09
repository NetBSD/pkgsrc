# $NetBSD: Makefile,v 1.17 2014/05/09 07:37:00 wiz Exp $

DISTNAME=	Cheetah-2.4.4
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:tl}
PKGREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	http://pypi.python.org/packages/source/C/Cheetah/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.cheetahtemplate.org/
COMMENT=	Python-powered template engine and code-generator

CONFLICTS=	Cheetah-[0-9]*
DEPENDS+=	${PYPKGPREFIX}-markdown>=2.0.1:../../textproc/py-markdown

USE_LANGUAGES=		c

PYTHON_VERSIONS_INCOMPATIBLE=	33 34 # not yet ported as of 2.4.4

REPLACE_PYTHON+=	SetupTools.py
REPLACE_PYTHON+=	bin/cheetah
REPLACE_PYTHON+=	bin/cheetah-analyze
REPLACE_PYTHON+=	bin/cheetah-compile
REPLACE_PYTHON+=	cheetah/CheetahWrapper.py
REPLACE_PYTHON+=	cheetah/Compiler.py
REPLACE_PYTHON+=	cheetah/DirectiveAnalyzer.py
REPLACE_PYTHON+=	cheetah/ImportHooks.py
REPLACE_PYTHON+=	cheetah/NameMapper.py
REPLACE_PYTHON+=	cheetah/Parser.py
REPLACE_PYTHON+=	cheetah/Servlet.py
REPLACE_PYTHON+=	cheetah/Tests/Analyzer.py
REPLACE_PYTHON+=	cheetah/Tests/CheetahWrapper.py
REPLACE_PYTHON+=	cheetah/Tests/Cheps.py
REPLACE_PYTHON+=	cheetah/Tests/Filters.py
REPLACE_PYTHON+=	cheetah/Tests/Misc.py
REPLACE_PYTHON+=	cheetah/Tests/NameMapper.py
REPLACE_PYTHON+=	cheetah/Tests/Parser.py
REPLACE_PYTHON+=	cheetah/Tests/Performance.py
REPLACE_PYTHON+=	cheetah/Tests/Regressions.py
REPLACE_PYTHON+=	cheetah/Tests/SyntaxAndOutput.py
REPLACE_PYTHON+=	cheetah/Tests/Template.py
REPLACE_PYTHON+=	cheetah/Tests/Test.py
REPLACE_PYTHON+=	cheetah/Tests/Unicode.py
REPLACE_PYTHON+=	cheetah/Utils/Misc.py
REPLACE_PYTHON+=	setup.py

.include "../../lang/python/application.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
