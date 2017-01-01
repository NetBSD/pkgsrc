# $NetBSD: Makefile,v 1.19 2017/01/01 14:43:51 wiz Exp $

DISTNAME=		kenosis-0.96
PKGNAME=		${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=		1
CATEGORIES=		net
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=kenosis/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://kenosis.sourceforge.net/
COMMENT=		P2P RPC system
LICENSE=		mit

DEPENDS+=		${PYPKGPREFIX}-expat-[0-9]*:../../textproc/py-expat

USE_LANGUAGES=		# empty

PYSETUP=		kenosis_setup.py
PYTHON_VERSIONS_INCOMPATIBLE=	34 35 36 # not yet ported as of 0.96

.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
