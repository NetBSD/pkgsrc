# $NetBSD: Makefile,v 1.11 2008/06/12 02:14:41 joerg Exp $
#

DISTNAME=		kenosis-0.941
PKGNAME=		${PYPKGPREFIX}-kenosis-0.94.1
PKGREVISION=		2
CATEGORIES=		net
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=kenosis/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://kenosis.sourceforge.net/
COMMENT=		P2P RPC system

PKG_DESTDIR_SUPPORT=	user-destdir

PYDISTUTILSPKG=		yes
PYSETUP=		kenosis_setup.py

.include "../../lang/python/extension.mk"
.include "../../textproc/py-xml/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
