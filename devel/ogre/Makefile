# $NetBSD: Makefile,v 1.18 2005/12/11 09:40:38 wiz Exp $
#

DISTNAME=	ogre-v0-12-1
PKGNAME=	ogre-0.12.1
PKGREVISION=	5
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=ogre/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://ogre.sourceforge.net/
COMMENT=	Object-Oriented Graphics Rendering Engine

WRKSRC=			${WRKDIR}/ogrenew
GNU_CONFIGURE=		yes
USE_TOOLS+=		gmake pkg-config
USE_LIBTOOL=		yes

CONFIGURE_ARGS+=	--with-platform=SDL

PKGCONFIG_OVERRIDE+=    OGRE.pc.in

.include "../../devel/devIL/buildlink3.mk"
.include "../../devel/SDL/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
