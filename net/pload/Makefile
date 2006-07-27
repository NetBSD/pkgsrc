# $NetBSD: Makefile,v 1.16 2006/07/27 00:09:06 hubertf Exp $
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
USE_X11BASE=	YES
INSTALL_TARGET=	install install.man

.include "../../mk/x11.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
