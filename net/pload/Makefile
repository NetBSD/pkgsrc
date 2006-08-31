# $NetBSD: Makefile,v 1.17 2006/08/31 18:31:01 hira Exp $
#

DISTNAME=	pload-0.9.4
PKGREVISION=	3
CATEGORIES=	net x11
MASTER_SITES=	http://www.engr.utk.edu/~mdsmith/pload/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.engr.utk.edu/~mdsmith/pload/
COMMENT=	PPP monitor for X11, monitoring totals and current in/out rates

PKG_INSTALLATION_TYPES=	overwrite pkgviews

HAS_CONFIGURE=	YES
USE_TOOLS+=	imake
USE_X11BASE=	YES
INSTALL_TARGET=	install install.man

.include "../../mk/x11.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
