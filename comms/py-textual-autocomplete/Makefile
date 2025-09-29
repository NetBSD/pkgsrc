# $NetBSD: Makefile,v 1.7 2025/09/29 12:10:39 adam Exp $

DISTNAME=	textual_autocomplete-4.0.6
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/_/-/}
CATEGORIES=	comms
MASTER_SITES=	${MASTER_SITE_PYPI:=t/textual_autocomplete/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://pypi.org/project/textual_autocomplete/
COMMENT=	Easily add autocomplete dropdowns to your Textual apps
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-hatchling-[0-9]*:../../devel/py-hatchling
DEPENDS+=	${PYPKGPREFIX}-textual>=2.0.0:../../comms/py-textual
DEPENDS+=	${PYPKGPREFIX}-typing-extensions>=4.5.0:../../devel/py-typing-extensions
TEST_DEPENDS+=	${PYPKGPREFIX}-testpath>=0:../../devel/py-testpath

USE_LANGUAGES=	# none

# as of 4.0.4
# 2 skipped, 4 warnings, 24 errors

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
