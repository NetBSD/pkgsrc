# $NetBSD: Makefile,v 1.10 2004/10/03 00:13:32 tv Exp $
#

DISTNAME=	ogre-v0-12-1
PKGNAME=	ogre-0.12.1
PKGREVISION=	2
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=ogre/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://ogre.sourceforge.net/
COMMENT=	Object-Oriented Graphics Rendering Engine

WRKSRC=			${WRKDIR}/ogrenew
GNU_CONFIGURE=		yes
USE_BUILDLINK3=		yes
USE_GNU_TOOLS+=		make
USE_LIBTOOL=		yes
USE_X11=		yes

CONFIGURE_ARGS+=	--with-platform=SDL

PKGCONFIG_OVERRIDE+=    OGRE.pc.in

.include "../../devel/devIL/buildlink3.mk"
.include "../../devel/SDL/buildlink3.mk"
.include "../../devel/pkgconfig/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
