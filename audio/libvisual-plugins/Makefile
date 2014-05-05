# $NetBSD: Makefile,v 1.43 2014/05/05 00:47:37 ryoon Exp $
#

DISTNAME=		libvisual-plugins-0.4.0
PKGREVISION=		23
CATEGORIES=		audio graphics
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=libvisual/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://localhost.nl/~synap/libvisual-wiki/
COMMENT=		Plugins for libvisual

CONFLICTS=		libvisual-nebulus-[0-9]* libvisual-gforce-[0-9]*

USE_PKGLOCALEDIR=	yes
USE_LANGUAGES=		c c++
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
USE_TOOLS+=		pkg-config mkdirhier yacc

.include "../../audio/libvisual/buildlink3.mk"
.include "../../graphics/glu/buildlink3.mk"
.include "../../graphics/MesaLib/buildlink3.mk"
# currently not useful, since libgdkpixbuf plugin is not configurable
#.include "../../x11/gtk2/buildlink3.mk"

# required for libGl check
BUILDLINK_DEPMETHOD.libXt?=	build
.include "../../x11/libXt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
