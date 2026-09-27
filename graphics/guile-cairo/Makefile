# $NetBSD: Makefile,v 1.39 2026/09/27 11:36:47 tnn Exp $

DISTNAME=	guile-cairo-1.11.2
PKGREVISION=	4
CATEGORIES=	graphics
MASTER_SITES=	https://download.savannah.gnu.org/releases/guile-cairo/

MAINTAINER=	gdt@NetBSD.org
HOMEPAGE=	https://www.nongnu.org/guile-cairo/
COMMENT=	Guile wrapper for cairo

LICENSE=	gnu-lgpl-v3

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config

INFO_FILES=	YES

PKGCONFIG_OVERRIDE+=	guile-cairo.pc.in

.include "../../graphics/cairo/buildlink3.mk"
.include "../../lang/guile20/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
