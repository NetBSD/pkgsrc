# $NetBSD: Makefile,v 1.1.1.1 2001/07/26 12:36:54 zuntum Exp $
#

DISTNAME=	xscorch-0.1.13a
CATEGORIES=	games
MASTER_SITES=	http://chaos2.org/xscorch/

MAINTAINER=	zuntum@netbsd.org
HOMEPAGE=	http://chaos2.org/xscorch/
COMMENT=	Multiplayer tank shoot-em-up

WRKSRC=		${WRKDIR}/xscorch-0.1.13

USE_BUILDLINK_ONLY=	YES
GNU_CONFIGURE=		YES

CONFIGURE_ARGS+=	--without-gnome

.include "../../audio/libmikmod/buildlink.mk"
.include "../../x11/gtk/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
