# $NetBSD: Makefile,v 1.1 2024/07/14 12:41:17 wiz Exp $

DISTNAME=	textual_autocomplete-3.0.0a9
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/_/-/:S/0a/0alpha/}
CATEGORIES=	comms
MASTER_SITES=	${MASTER_SITE_PYPI:=t/textual_autocomplete/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://pypi.org/project/textual_autocomplete/
COMMENT=	Easily add autocomplete dropdowns to your Textual apps
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-poetry-core-[0-9]*:../../devel/py-poetry-core
DEPENDS+=	${PYPKGPREFIX}-textual>=0.58.0:../../comms/py-textual
DEPENDS+=	${PYPKGPREFIX}-typing-extensions>=4.5.0:../../devel/py-typing-extensions

USE_LANGUAGES=	# none

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
