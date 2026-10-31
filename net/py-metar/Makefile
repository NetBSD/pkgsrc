# $NetBSD: Makefile,v 1.16 2026/10/31 13:09:38 wiz Exp $

DISTNAME=	pymetar-1.4
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/py//}
PKGREVISION=	1
CATEGORIES=	net python
MASTER_SITES=	https://www.schwarzvogel.de/pkgs/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.schwarzvogel.de/software/pymetar/
COMMENT=	Downloads weather reports
LICENSE=	gnu-gpl-v2 # or later

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=84.2:../../devel/py-setuptools

PY_RENAME_BINARIES=	pymetar

.include "../../lang/python/application.mk"
.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
