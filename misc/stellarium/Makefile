# $NetBSD: Makefile,v 1.2 2004/10/03 00:13:00 tv Exp $
#

DISTNAME=		stellarium-0.6.0
PKGREVISION=	1
CATEGORIES=		misc
MASTER_SITES=		http://stellarium.free.fr/download/

MAINTAINER=		dotz@irc.pl
HOMEPAGE=		http://stellarium.free.fr/
COMMENT=		Generate photorealistic skys with OpenGL

USE_BUILDLINK3=		yes
USE_GNU_TOOLS+=		make
USE_X11=		yes
GNU_CONFIGURE=		yes

.include "../../devel/SDL/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
