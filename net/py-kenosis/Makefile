# $NetBSD: Makefile,v 1.3 2005/02/04 17:24:16 drochner Exp $
#

DISTNAME=		kenosis-0.941
PKGNAME=		${PYPKGPREFIX}-kenosis-0.94.1
CATEGORIES=		net
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=kenosis/}

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://kenosis.sourceforge.net/
COMMENT=		P2P RPC system

USE_BUILDLINK3=		yes
PYTHON_VERSIONS_ACCEPTED= 23 24 22 21
PYDISTUTILSPKG=		yes
PYSETUP=		kenosis_setup.py

.include "../../lang/python/extension.mk"
.include "../../textproc/py-xml/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
