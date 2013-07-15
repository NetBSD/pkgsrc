# $NetBSD: Makefile,v 1.27 2013/07/15 02:02:22 ryoon Exp $

DISTNAME=	xscorch-0.2.0
PKGREVISION=	8
CATEGORIES=	games
MASTER_SITES=	http://www.xscorch.org/releases/

MAINTAINER=	snj@NetBSD.org
HOMEPAGE=	http://www.xscorch.org/
COMMENT=	Multiplayer tank shoot-em-up

USE_LIBTOOL=		YES
USE_TOOLS+=		perl
GNU_CONFIGURE=		YES

CONFIGURE_ARGS+=	--without-gnome

.include "../../audio/libmikmod/buildlink3.mk"
.include "../../mk/readline.buildlink3.mk"
.include "../../x11/gtk/buildlink3.mk"
.include "../../x11/libXpm/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
