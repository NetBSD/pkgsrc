# $NetBSD: Makefile,v 1.13 2019/04/25 07:32:51 maya Exp $

DISTNAME=	nts-78
PKGREVISION=	2
CATEGORIES=	editors
MASTER_SITES=	http://www.duke.edu/~dgraham/NTS/

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	http://www.duke.edu/~dgraham/NTS/
COMMENT=	Simple GUI note taking application
LICENSE=	gnu-gpl-v2

DEPENDS+=	${PYPKGPREFIX}-dateutil-[0-9]*:../../time/py-dateutil
DEPENDS+=	${PYPKGPREFIX}-wxWidgets>=2.8.7:../../x11/py-wxWidgets

PYTHON_VERSIONS_INCOMPATIBLE=	34 35 36 37 # py-wxWidgets

USE_LANGUAGES=	# none

PYDISTUTILSPKG=	yes

.include "../../lang/python/application.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
