# $NetBSD: Makefile,v 1.17.2.1 2008/06/08 12:38:11 tron Exp $
#

DISTNAME=		exiv2-0.16
PKGREVISION=		1
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

.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../textproc/expat/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
