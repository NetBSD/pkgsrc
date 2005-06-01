# $NetBSD: Makefile,v 1.6 2005/06/01 18:03:05 jlam Exp $
#

DISTNAME=		stellarium-0.6.0
PKGREVISION=	2
CATEGORIES=		misc
MASTER_SITES=		http://stellarium.free.fr/download/

MAINTAINER=		dotz@irc.pl
HOMEPAGE=		http://stellarium.free.fr/
COMMENT=		Generate photorealistic skys with OpenGL

USE_TOOLS+=		gmake
GNU_CONFIGURE=		yes

.include "../../devel/SDL/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
