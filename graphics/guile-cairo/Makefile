# $NetBSD: Makefile,v 1.35 2024/09/21 13:16:16 gdt Exp $

DISTNAME=	guile-cairo-1.11.2
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
