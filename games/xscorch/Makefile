# $NetBSD: Makefile,v 1.3 2002/02/10 23:43:55 abs Exp $
#

DISTNAME=	xscorch-0.1.14
CATEGORIES=	games
MASTER_SITES=	http://chaos2.org/xscorch/

MAINTAINER=	zuntum@netbsd.org
HOMEPAGE=	http://chaos2.org/xscorch/
COMMENT=	Multiplayer tank shoot-em-up

USE_BUILDLINK_ONLY=	YES
GNU_CONFIGURE=		YES

CONFIGURE_ARGS+=	--without-gnome

.include "../../audio/libmikmod/buildlink.mk"
.include "../../graphics/xpm/buildlink.mk"
.include "../../x11/gtk/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
