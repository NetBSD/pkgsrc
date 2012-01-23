# $NetBSD: Makefile,v 1.13 2012/01/23 10:38:05 obache Exp $
#

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

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=		# empty

PYSETUP=		kenosis_setup.py

.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
