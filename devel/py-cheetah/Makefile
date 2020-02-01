# $NetBSD: Makefile,v 1.26 2020/02/01 19:56:21 adam Exp $

DISTNAME=	Cheetah-2.4.4
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:tl}
PKGREVISION=	2
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=C/Cheetah/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.cheetahtemplate.org/
COMMENT=	Python-powered template engine and code-generator

CONFLICTS=	Cheetah-[0-9]*
DEPENDS+=	${PYPKGPREFIX}-markdown>=2.0.1:../../textproc/py-markdown

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

PYTHON_VERSIONS_ACCEPTED=	27 # for 3.x, use py-cheetah3

post-install:
	cd ${DESTDIR}${PREFIX}/bin && \
	${MV} cheetah cheetah-${PYVERSSUFFIX} && \
	${MV} cheetah-analyze cheetah-analyze-${PYVERSSUFFIX} && \
	${MV} cheetah-compile cheetah-compile-${PYVERSSUFFIX} || ${TRUE}

.include "../../lang/python/application.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
