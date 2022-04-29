# $NetBSD: Makefile,v 1.1 2022/04/29 13:05:35 wiz Exp $

DISTNAME=	ephemeral_port_reserve-1.1.4
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	net python
MASTER_SITES=	${MASTER_SITE_PYPI:=e/ephemeral_port_reserve/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/Yelp/ephemeral-port-reserve/
COMMENT=	Bind to ephemeral port, force it into TIME_WAIT state, and unbind it
LICENSE=	mit

post-install:
	${MV} ${DESTDIR}${PREFIX}/bin/ephemeral-port-reserve ${DESTDIR}${PREFIX}/bin/ephemeral-port-reserve-${PYVERSSUFFIX} || ${TRUE}

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
