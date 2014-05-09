# $NetBSD: Makefile,v 1.7 2014/05/09 07:37:04 wiz Exp $

DISTNAME=	nts-78
PKGREVISION=	1
CATEGORIES=	editors
MASTER_SITES=	http://www.duke.edu/~dgraham/NTS/

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	http://www.duke.edu/~dgraham/NTS/
COMMENT=	Simple GUI note taking application
LICENSE=	gnu-gpl-v2

DEPENDS+=	${PYPKGPREFIX}-wxWidgets>=2.8.7:../../x11/py-wxWidgets

PYTHON_VERSIONED_DEPENDENCIES=	dateutil
PYTHON_VERSIONS_INCOMPATIBLE=	33 34 # py-wxWidgets

USE_LANGUAGES=	# none

PYDISTUTILSPKG=	yes

.include "../../lang/python/application.mk"
.include "../../lang/python/egg.mk"
.include "../../lang/python/versioned_dependencies.mk"
.include "../../mk/bsd.pkg.mk"
