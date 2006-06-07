# $NetBSD: Makefile,v 1.8 2006/06/07 12:53:13 joerg Exp $
#

DISTNAME=		kenosis-0.941
PKGNAME=		${PYPKGPREFIX}-kenosis-0.94.1
PKGREVISION=		2
CATEGORIES=		net
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=kenosis/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://kenosis.sourceforge.net/
COMMENT=		P2P RPC system

PYTHON_VERSIONS_ACCEPTED= 23 24 22
PYDISTUTILSPKG=		yes
PYSETUP=		kenosis_setup.py

.include "../../lang/python/extension.mk"
.include "../../textproc/py-xml/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
