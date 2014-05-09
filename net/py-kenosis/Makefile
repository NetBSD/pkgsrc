# $NetBSD: Makefile,v 1.16 2014/05/09 07:37:15 wiz Exp $

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
PYTHON_VERSIONS_INCOMPATIBLE=	33 34 # not yet ported as of 0.96

.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
