# $NetBSD: Makefile,v 1.13 2004/02/01 01:43:29 jlam Exp $
#

DISTNAME=		aqsis-0.6.4
PKGREVISION=		2
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

USE_BUILDLINK2=		yes
GCC_REQD+=		2.95.3
USE_GCC_SHLIB=		yes

.include "../../devel/libargparse/buildlink2.mk"
.include "../../graphics/Mesa/buildlink2.mk"
.include "../../graphics/tiff/buildlink2.mk"

.include "../../mk/bsd.pkg.mk"
