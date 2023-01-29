# $NetBSD: Makefile,v 1.31 2023/01/29 21:16:36 ryoon Exp $

DISTNAME=	guile-cairo-1.4.1
PKGREVISION=	9
CATEGORIES=	graphics
MASTER_SITES=	http://download.gna.org/guile-cairo/
# guile-cario has moved to savannah and is at 1.9.1, but that is
# a prerlease and hence not packaged.

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
