# $NetBSD: Makefile,v 1.11 2025/04/12 09:50:45 adam Exp $

DISTNAME=	ct3-3.4.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/ct3/cheetah/}
PKGREVISION=	2
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=c/ct3/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://cheetahtemplate.org/
COMMENT=	Template engine and code generation tool
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools

CONFLICTS=	Cheetah-[0-9]*

REPLACE_PYTHON+=	Cheetah/CheetahWrapper.py
REPLACE_PYTHON+=	Cheetah/DirectiveAnalyzer.py
REPLACE_PYTHON+=	Cheetah/Filters.py
REPLACE_PYTHON+=	Cheetah/NameMapper.py
REPLACE_PYTHON+=	Cheetah/Servlet.py
REPLACE_PYTHON+=	Cheetah/Templates/SkeletonPage.py
REPLACE_PYTHON+=	Cheetah/Tests/CheetahWrapper.py
REPLACE_PYTHON+=	Cheetah/Tests/Performance.py
REPLACE_PYTHON+=	Cheetah/Tests/SyntaxAndOutput.py
REPLACE_PYTHON+=	Cheetah/Tests/Test.py
REPLACE_PYTHON+=	Cheetah/Tools/SiteHierarchy.py
REPLACE_PYTHON+=	Cheetah/Version.py

post-install:
	cd ${DESTDIR}${PREFIX}/bin && \
	${MV} cheetah cheetah-${PYVERSSUFFIX} && \
	${MV} cheetah-analyze cheetah-analyze-${PYVERSSUFFIX} && \
	${MV} cheetah-compile cheetah-compile-${PYVERSSUFFIX} || ${TRUE}

.include "../../lang/python/application.mk"
.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
