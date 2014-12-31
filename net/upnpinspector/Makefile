# $NetBSD: Makefile,v 1.9 2014/12/31 13:57:29 wiz Exp $

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

PYTHON_VERSIONS_INCOMPATIBLE=	33 34 # py-gtk2

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
