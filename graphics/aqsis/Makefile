# $NetBSD: Makefile,v 1.15 2004/10/03 00:14:48 tv Exp $
#

DISTNAME=		aqsis-0.6.4
PKGREVISION=		3
CATEGORIES=		graphics
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=aqsis/}

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://www.aqsis.com/
COMMENT=		Renderman clone

GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes
LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig
USE_GNU_TOOLS+=		make
USE_X11=		yes

USE_BUILDLINK3=		yes
GCC_REQD+=		2.95.3
USE_GCC_SHLIB=		yes

.include "../../devel/libargparse/buildlink3.mk"
.include "../../graphics/Mesa/buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
