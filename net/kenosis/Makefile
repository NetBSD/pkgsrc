# $NetBSD: Makefile,v 1.1.1.1 2005/01/10 10:20:11 drochner Exp $
#

DISTNAME=		kenosis-0.92
PKGNAME=		${PYPKGPREFIX}-kenosis-0.92
CATEGORIES=		net
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=kenosis/}

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://kenosis.sourceforge.net/
COMMENT=		P2P RPC system

USE_BUILDLINK3=		yes
PYTHON_VERSIONS_ACCEPTED= 23pth 24pth 22pth 21pth
PYDISTUTILSPKG=		yes
PYSETUP=		kenosis_setup.py

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
