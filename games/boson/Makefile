# $NetBSD: Makefile,v 1.2 2003/12/08 14:41:39 wiz Exp $
#

DISTNAME=		boson-all-0.8
PKGNAME=		${DISTNAME:S/-all//}
PKGREVISION=		1
CATEGORIES=		games
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=boson/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		xtraeme@NetBSD.org
HOMEPAGE=		http://boson.eu.org/
COMMENT=		OpenGL real-time strategy game for KDE 3

BUILD_USES_MSGFMT=	yes

USE_BUILDLINK2=		yes
USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes
USE_X11=		yes
USE_GMAKE=		yes
USE_LIBTOOL=		yes

CONFIGURE_ARGS+=	--disable-debug
LIBTOOL_OVERRIDE=       ${WRKSRC}/libtool

.include "../../audio/libvorbis/buildlink2.mk"
.include "../../devel/SDL/buildlink2.mk"
.include "../../games/kdegames3/buildlink2.mk"
.include "../../graphics/jpeg/buildlink2.mk"
.include "../../graphics/lib3ds/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
