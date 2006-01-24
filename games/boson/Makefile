# $NetBSD: Makefile,v 1.16 2006/01/24 07:32:08 wiz Exp $
#

DISTNAME=		boson-all-0.8
PKGNAME=		${DISTNAME:S/-all//}
PKGREVISION=		8
CATEGORIES=		games
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=boson/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://boson.eu.org/
COMMENT=		OpenGL real-time strategy game for KDE 3

BUILD_USES_MSGFMT=	yes

USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes
USE_TOOLS+=		gmake
USE_LIBTOOL=		yes

CONFIGURE_ARGS+=	--disable-debug

.include "../../audio/libvorbis/buildlink3.mk"
.include "../../devel/SDL/buildlink3.mk"
.include "../../games/kdegames3/buildlink3.mk"
.include "../../graphics/jpeg/buildlink3.mk"
.include "../../graphics/lib3ds/buildlink3.mk"
.include "../../meta-pkgs/kde3/kde3.mk"
.include "../../mk/bsd.pkg.mk"
