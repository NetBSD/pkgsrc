# $NetBSD: Makefile,v 1.2 2024/10/19 10:52:51 wiz Exp $

DISTNAME=	textual_autocomplete-3.0.0a12
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/_/-/}
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
