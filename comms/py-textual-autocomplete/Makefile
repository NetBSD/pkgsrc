# $NetBSD: Makefile,v 1.3 2024/11/24 10:37:43 wiz Exp $

DISTNAME=	textual_autocomplete-3.0.0a13
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/_/-/}
CATEGORIES=	comms
MASTER_SITES=	${MASTER_SITE_PYPI:=t/textual_autocomplete/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://pypi.org/project/textual_autocomplete/
COMMENT=	Easily add autocomplete dropdowns to your Textual apps
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-hatchling-[0-9]*:../../devel/py-hatchling
DEPENDS+=	${PYPKGPREFIX}-textual>=0.58.0:../../comms/py-textual
DEPENDS+=	${PYPKGPREFIX}-typing-extensions>=4.5.0:../../devel/py-typing-extensions

USE_LANGUAGES=	# none

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
