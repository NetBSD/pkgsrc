# $NetBSD: Makefile,v 1.27 2023/10/23 06:37:50 wiz Exp $

DISTNAME=		kenosis-0.96
PKGNAME=		${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=		3
CATEGORIES=		net
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=kenosis/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://kenosis.sourceforge.net/
COMMENT=		P2P RPC system
LICENSE=		mit

USE_LANGUAGES=		# empty

PYSETUP=		kenosis_setup.py
PYTHON_VERSIONS_ACCEPTED=	27 # not yet ported as of 0.96

.include "../../lang/python/batteries-included.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
