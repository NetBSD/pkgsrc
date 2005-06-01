# $NetBSD: Makefile,v 1.15 2005/06/01 18:02:44 jlam Exp $
#

DISTNAME=	ogre-v0-12-1
PKGNAME=	ogre-0.12.1
PKGREVISION=	4
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=ogre/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://ogre.sourceforge.net/
COMMENT=	Object-Oriented Graphics Rendering Engine

WRKSRC=			${WRKDIR}/ogrenew
GNU_CONFIGURE=		yes
USE_TOOLS+=		gmake
USE_LIBTOOL=		yes

CONFIGURE_ARGS+=	--with-platform=SDL

PKGCONFIG_OVERRIDE+=    OGRE.pc.in

.include "../../devel/devIL/buildlink3.mk"
.include "../../devel/SDL/buildlink3.mk"
.include "../../devel/pkgconfig/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
