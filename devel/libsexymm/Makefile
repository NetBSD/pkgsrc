# $NetBSD: Makefile,v 1.2 2007/07/28 15:25:02 drochner Exp $
#

DISTNAME=	libsexymm-0.1.9
CATEGORIES=	devel
MASTER_SITES=	http://releases.chipx86.com/libsexy/libsexymm/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.chipx86.com/wiki/Libsexy
COMMENT=	C++ bindings for libsexy

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config gmake
USE_LANGUAGES=	c c++

PKGCONFIG_OVERRIDE+=	libsexy/libsexymm.pc.in

.include "../../x11/gtkmm/buildlink3.mk"
.include "../../devel/libsexy/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
