# $NetBSD: Makefile,v 1.55 2023/12/30 21:00:08 zafer Exp $
#

DISTNAME=	libsexymm-0.1.9
PKGREVISION=	47
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
