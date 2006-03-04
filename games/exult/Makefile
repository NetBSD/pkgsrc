# $NetBSD: Makefile,v 1.6 2006/03/04 21:29:41 jlam Exp $
#

DISTNAME=		exult-1.2
PKGREVISION=		3
CATEGORIES=		games
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=exult/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://exult.sourceforge.net/
COMMENT=		Open-source Ultima 7 engine

USE_PKGLOCALEDIR=	yes
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes

.include "../../devel/SDL/buildlink3.mk"
.include "../../audio/SDL_mixer/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
