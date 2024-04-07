# $NetBSD: Makefile,v 1.56 2024/04/07 07:33:47 wiz Exp $
#

DISTNAME=	libsexymm-0.1.9
PKGREVISION=	48
CATEGORIES=	devel
MASTER_SITES=	https://releases.chipx86.com/libsexy/libsexymm/

MAINTAINER=	pkgsrc-users@NetBSD.org
#HOMEPAGE=	http://www.chipx86.com/wiki/Libsexy
COMMENT=	C++ bindings for libsexy

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config gmake
USE_LANGUAGES=	c c++11

PKGCONFIG_OVERRIDE+=	libsexy/libsexymm.pc.in

.include "../../x11/gtkmm/buildlink3.mk"
.include "../../devel/libsexy/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
