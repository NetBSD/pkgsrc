# $NetBSD: Makefile,v 1.15 2026/10/27 00:03:13 gdt Exp $

DISTNAME=	pymetar-1.4
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/py//}
CATEGORIES=	net python
MASTER_SITES=	https://www.schwarzvogel.de/pkgs/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.schwarzvogel.de/software/pymetar/
COMMENT=	Downloads weather reports
LICENSE=	gnu-gpl-v2 # or later

post-extract:
	${MV} ${WRKSRC}/bin/pymetar ${WRKSRC}/bin/pymetar${PYVERSSUFFIX}

.include "../../lang/python/application.mk"
.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
