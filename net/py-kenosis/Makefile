# $NetBSD: Makefile,v 1.12 2011/06/14 08:48:09 obache Exp $
#

DISTNAME=		kenosis-0.96
PKGNAME=		${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=		net
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=kenosis/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://kenosis.sourceforge.net/
COMMENT=		P2P RPC system
LICENSE=		mit

PKG_DESTDIR_SUPPORT=	user-destdir

PYSETUP=		kenosis_setup.py

.include "../../lang/python/distutils.mk"
.include "../../textproc/py-xml/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
