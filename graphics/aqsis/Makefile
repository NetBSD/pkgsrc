# $NetBSD: Makefile,v 1.1.1.1 2002/10/28 15:12:36 agc Exp $
#

DISTNAME=		aqsis-0.6.4
CATEGORIES=		graphics
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=aqsis/}

MAINTAINER=		packages@netbsd.org
HOMEPAGE=		http://www.aqsis.org/
COMMENT=		Renderman clone

GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes
LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig
USE_GMAKE=		yes
USE_X11=		yes

USE_BUILDLINK2=		yes

.include "../../devel/libargparse/buildlink2.mk"
.include "../../graphics/Mesa/buildlink2.mk"
.include "../../graphics/tiff/buildlink2.mk"

.include "../../mk/bsd.pkg.mk"
