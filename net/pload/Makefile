# $NetBSD: Makefile,v 1.20 2007/12/09 23:41:11 wiz Exp $
#

DISTNAME=	pload-0.9.5
CATEGORIES=	net x11
MASTER_SITES=	${MASTER_SITE_SUNSITE:=system/network/serial/ppp/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://web.archive.org/web/20050305142516/http://www.engr.utk.edu/~mdsmith/pload/
COMMENT=	PPP monitor for X11, monitoring totals and current in/out rates

PKG_INSTALLATION_TYPES=	overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir

HAS_CONFIGURE=	YES
USE_TOOLS+=	imake
USE_X11BASE=	YES
INSTALL_TARGET=	install install.man

.include "../../x11/libXaw/buildlink3.mk"
.include "../../x11/libXp/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
