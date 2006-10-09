# $NetBSD: Makefile,v 1.11 2006/10/09 10:48:41 gdt Exp $
#

DISTNAME=		exiv2-0.11
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

.include "../../mk/bsd.pkg.mk"
