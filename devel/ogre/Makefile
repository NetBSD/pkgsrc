# $NetBSD: Makefile,v 1.46 2020/06/05 12:48:59 jperkin Exp $
#

DISTNAME=	ogre-v1-6-3
PKGNAME=	ogre-1.6.3
PKGREVISION=	15
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=ogre/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://ogre.sourceforge.net/
COMMENT=	Object-Oriented Graphics Rendering Engine
LICENSE=	gnu-lgpl-v2.1

WRKSRC=			${WRKDIR}/ogre
GNU_CONFIGURE=		yes
USE_TOOLS+=		gmake pkg-config xmkmf
USE_LANGUAGES=		c c++03
USE_LIBTOOL=		yes

CONFIGURE_ARGS+=	--with-platform=GLX
CONFIGURE_ARGS+=	--disable-freeimage
CONFIGURE_ARGS+=	--disable-cg

PKGCONFIG_OVERRIDE+=	OGRE.pc.in

.include "../../archivers/zziplib/buildlink3.mk"
.include "../../devel/devIL/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/MesaLib/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../graphics/glu/buildlink3.mk"
.include "../../x11/libXaw/buildlink3.mk"
.include "../../x11/libXxf86vm/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
