# $NetBSD: Makefile,v 1.3 2003/05/02 11:55:03 wiz Exp $
#

DISTNAME=	marbles-1.0.2
PKGREVISION=	1
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=lgames/}

MAINTAINER=	xs@nitric.net
HOMEPAGE=	http://lgames.sourceforge.net/
COMMENT=	Atomix-like puzzle

USE_BUILDLINK2=		YES
USE_X11=		YES
GNU_CONFIGURE=		YES
CONFIGURE_ARGS+=	--with-profile-path=${LOCALBASE}/share/games/

.include "../../devel/SDL/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
