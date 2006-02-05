# $NetBSD: Makefile,v 1.6 2006/02/05 23:10:30 joerg Exp $
#

DISTNAME=		kenosis-0.941
PKGNAME=		${PYPKGPREFIX}-kenosis-0.94.1
PKGREVISION=		2
CATEGORIES=		net
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=kenosis/}

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://kenosis.sourceforge.net/
COMMENT=		P2P RPC system

PYTHON_VERSIONS_ACCEPTED= 23 24 22 21
PYDISTUTILSPKG=		yes
PYSETUP=		kenosis_setup.py

.include "../../lang/python/extension.mk"
.include "../../textproc/py-xml/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
