# $NetBSD: Makefile,v 1.3 2005/04/11 21:45:49 tv Exp $
#

DISTNAME=		exult-1.2
PKGREVISION=		1
CATEGORIES=		games
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=exult/}

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://exult.sourceforge.net/
COMMENT=		Open-source Ultima 7 engine

USE_PKGLOCALEDIR=	yes
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes

.include "../../devel/SDL/buildlink3.mk"
.include "../../audio/SDL_mixer/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
