# $NetBSD: Makefile,v 1.16 2007/07/17 19:29:30 drochner Exp $
#

DISTNAME=		exiv2-0.15
CATEGORIES=		graphics
MASTER_SITES=		http://www.exiv2.org/

MAINTAINER=		gdt@NetBSD.org
HOMEPAGE=		http://www.exiv2.org/
COMMENT=		Image metadata manipulation

USE_LANGUAGES=		c c++
GCC_REQD+=		3.3
USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes
USE_TOOLS+=		gmake
USE_LIBTOOL=		yes
PKGCONFIG_OVERRIDE=	config/exiv2.pc.in

.include "../../devel/zlib/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
