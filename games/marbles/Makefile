# $NetBSD: Makefile,v 1.6 2004/03/07 06:16:46 snj Exp $

DISTNAME=	marbles-1.0.2
PKGREVISION=	3
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=lgames/}

MAINTAINER=	xs@nitric.net
HOMEPAGE=	http://lgames.sourceforge.net/
COMMENT=	Atomix-like puzzle

USE_BUILDLINK3=		YES
USE_X11=		YES
GNU_CONFIGURE=		YES
CONFIGURE_ARGS+=	--with-profile-path=${LOCALBASE}/share/games/

.include "../../devel/SDL/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
