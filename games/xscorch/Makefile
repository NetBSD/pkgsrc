# $NetBSD: Makefile,v 1.4 2002/08/31 13:33:02 wiz Exp $
#

DISTNAME=	xscorch-0.1.15
CATEGORIES=	games
MASTER_SITES=	http://chaos2.org/xscorch/

MAINTAINER=	zuntum@netbsd.org
HOMEPAGE=	http://chaos2.org/xscorch/
COMMENT=	Multiplayer tank shoot-em-up

USE_BUILDLINK2=		YES
GNU_CONFIGURE=		YES

CONFIGURE_ARGS+=	--without-gnome

.include "../../audio/libmikmod/buildlink2.mk"
.include "../../graphics/xpm/buildlink2.mk"
.include "../../x11/gtk/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
