# $NetBSD: Makefile,v 1.18 2006/10/04 21:53:17 wiz Exp $
#

DISTNAME=	pload-0.9.4
PKGREVISION=	3
CATEGORIES=	net x11
MASTER_SITES=	${MASTER_SITE_SUNSITE:=system/network/serial/ppp/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://web.archive.org/web/20050305142516/http://www.engr.utk.edu/~mdsmith/pload/
COMMENT=	PPP monitor for X11, monitoring totals and current in/out rates

PKG_INSTALLATION_TYPES=	overwrite pkgviews

HAS_CONFIGURE=	YES
USE_TOOLS+=	imake
USE_X11BASE=	YES
INSTALL_TARGET=	install install.man

.include "../../mk/x11.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
