# $NetBSD: Makefile,v 1.1.1.1 2003/12/03 19:01:46 xtraeme Exp $
#

DISTNAME=	ogre-v0-12-1
PKGNAME=	ogre-0.12.1
WRKSRC=		${WRKDIR}/ogrenew
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=ogre/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	xtraeme@NetBSD.org
HOMEPAGE=	http://ogre.sourceforge.net/
COMMENT=	Object-Oriented Graphics Rendering Engine

GNU_CONFIGURE=		yes
USE_BUILDLINK2=		yes
USE_GMAKE=		yes
USE_LIBTOOL=		yes
USE_X11=		yes

CONFIGURE_ARGS+=	--with-platform=SDL

LIBTOOL_OVERRIDE=       ${WRKSRC}/libtool
PKGCONFIG_OVERRIDE+=    ${WRKSRC}/OGRE.pc.in

.include "../../devel/SDL/buildlink2.mk"
.include "../../devel/pkgconfig/buildlink2.mk"
.include "../../devel/zlib/buildlink2.mk"
.include "../../graphics/freetype2/buildlink2.mk"
.include "../../wip/devIL/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
