# $NetBSD: Makefile,v 1.4 2024/06/05 22:44:58 wiz Exp $

DISTNAME=	ipcalc-1.99.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	net python
MASTER_SITES=	${MASTER_SITE_PYPI:=i/ipcalc/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/tehmaze/ipcalc/
COMMENT=	IP subnet calculator
LICENSE=	2-clause-bsd

USE_LANGUAGES=	# none

PYTHON_27_ACCEPTED=	yes

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
