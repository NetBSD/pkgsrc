# $NetBSD: Makefile,v 1.10 2015/12/05 21:25:55 adam Exp $

DISTNAME=	UPnP-Inspector-0.2.2
PKGREVISION=	3
CATEGORIES=	net
MASTER_SITES=	http://coherence.beebits.net/download/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://coherence.beebits.net/
COMMENT=	UPnP analyzer
LICENSE=	mit

DEPENDS+=	coherence>=0.6.4:../../net/coherence
DEPENDS+=	${PYPKGPREFIX}-gtk2-[0-9]*:../../x11/py-gtk2

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	33 34 35 # py-gtk2

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
