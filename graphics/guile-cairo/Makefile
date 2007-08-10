# $NetBSD: Makefile,v 1.1.1.1 2007/08/10 21:21:01 gdt Exp $
#

DISTNAME=	guile-cairo-1.4.0
CATEGORIES=	graphics
MASTER_SITES=	http://download.gna.org/guile-cairo/

MAINTAINER=	gdt@NetBSD.org
HOMEPAGE=	http://download.gna.org/guile-cairo/
COMMENT=	Guile wrapper for cairo

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config

INFO_FILES=	# PLIST

PKGCONFIG_OVERRIDE+=	guile-cairo.pc.in

.include "../../graphics/cairo/buildlink3.mk"
.include "../../lang/guile/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
