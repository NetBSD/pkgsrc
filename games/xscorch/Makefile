# $NetBSD: Makefile,v 1.16 2006/02/05 23:09:25 joerg Exp $

DISTNAME=	xscorch-0.2.0
PKGREVISION=	2
CATEGORIES=	games
MASTER_SITES=	http://www.xscorch.org/releases/

MAINTAINER=	snj@NetBSD.org
HOMEPAGE=	http://www.xscorch.org/
COMMENT=	Multiplayer tank shoot-em-up

USE_LIBTOOL=		YES
GNU_CONFIGURE=		YES

CONFIGURE_ARGS+=	--without-gnome

.include "../../audio/libmikmod/buildlink3.mk"
.include "../../graphics/xpm/buildlink3.mk"
.include "../../x11/gtk/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
