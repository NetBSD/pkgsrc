# $NetBSD: Makefile,v 1.8 2003/07/17 21:39:45 grant Exp $
#

DISTNAME=	xscorch-0.1.15
PKGREVISION=	2
CATEGORIES=	games
MASTER_SITES=	http://chaos2.org/xscorch/

MAINTAINER=	zuntum@NetBSD.org
HOMEPAGE=	http://chaos2.org/xscorch/
COMMENT=	Multiplayer tank shoot-em-up

USE_BUILDLINK2=		YES
USE_LIBTOOL=		YES
GNU_CONFIGURE=		YES

LIBTOOL_OVERRIDE=	${WRKSRC}/libtool

CONFIGURE_ARGS+=	--without-gnome

.include "../../audio/libmikmod/buildlink2.mk"
.include "../../graphics/xpm/buildlink2.mk"
.include "../../x11/gtk/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
