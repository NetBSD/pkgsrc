# $NetBSD: Makefile,v 1.2 2024/10/13 09:33:44 wiz Exp $

DISTNAME=	fritzconnection-1.13.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	net python
MASTER_SITES=	${MASTER_SITE_PYPI:=f/fritzconnection/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/kbr/fritzconnection
COMMENT=	Communicate with the AVM FRITZ!Box
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=0:../../devel/py-setuptools
TOOL_DEPENDS+=	${PYPKGPREFIX}-wheel>=0:../../devel/py-wheel
DEPENDS+=	${PYPKGPREFIX}-requests>=2.22.0:../../devel/py-requests

USE_LANGUAGES=	# none

post-install:
.for f in fritzcall fritzconnection fritzhomeauto fritzhosts fritzmonitor fritzphonebook fritzstatus fritzwlan
	cd ${DESTDIR}${PREFIX}/bin && ${MV} ${f} ${f}-${PYVERSSUFFIX} || ${TRUE}
.endfor

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
