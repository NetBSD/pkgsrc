# $NetBSD: Makefile,v 1.2 2022/03/21 22:07:57 rillig Exp $

DISTNAME=	xchomp-pl1
PKGNAME=	xchomp-1.1pl1
CATEGORIES=	games
MASTER_SITES=	https://ftp.gwdg.de/pub/x11/x.org/R5contrib/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://vidalc.chez.com/xchomp/xchomp.html
COMMENT=	Game for X11 closely patterned after Pac-Man

WRKSRC=		${WRKDIR}/xchomp
USE_IMAKE=	yes

.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
