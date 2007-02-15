# $NetBSD: Makefile,v 1.29 2007/02/15 14:58:19 joerg Exp $
#

DISTNAME=		aqsis-0.6.4
PKGREVISION=		6
CATEGORIES=		graphics
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=aqsis/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.aqsis.com/
COMMENT=		Renderman clone

GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes
USE_TOOLS+=		gmake

GCC_REQD+=		2.95.3
USE_LANGUAGES+=		c c++

.include "../../devel/libargparse/buildlink3.mk"
.include "../../graphics/Mesa/buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"
.include "../../mk/dlopen.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
