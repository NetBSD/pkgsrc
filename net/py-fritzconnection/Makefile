# $NetBSD: Makefile,v 1.4 2025/04/15 05:38:03 adam Exp $

DISTNAME=	fritzconnection-1.13.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	net python
MASTER_SITES=	${MASTER_SITE_PYPI:=f/fritzconnection/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/kbr/fritzconnection
COMMENT=	Communicate with the AVM FRITZ!Box
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools
DEPENDS+=	${PYPKGPREFIX}-requests>=2.22.0:../../devel/py-requests

USE_LANGUAGES=	# none

post-install:
.for f in fritzcall fritzconnection fritzhomeauto fritzhosts fritzmonitor fritzphonebook fritzstatus fritzwlan
	cd ${DESTDIR}${PREFIX}/bin && ${MV} ${f} ${f}-${PYVERSSUFFIX} || ${TRUE}
.endfor

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
