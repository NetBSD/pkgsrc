# $NetBSD: Makefile,v 1.4 2004/10/03 00:14:43 tv Exp $
#

DISTNAME=		dd2-0.2.1
PKGREVISION=	1
CATEGORIES=		games
MASTER_SITES=		http://www.usebox.net/jjm/dd2/releases/

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://www.usebox.net/jjm/dd2/
COMMENT=		Shoot'em up arcade game for one or two players

USE_BUILDLINK3=		yes
USE_X11=		yes
GNU_CONFIGURE=		yes

.include "../../audio/SDL_mixer/buildlink3.mk"
.include "../../devel/SDL/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
