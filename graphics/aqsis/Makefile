# $NetBSD: Makefile,v 1.19 2005/05/22 20:08:04 jlam Exp $
#

DISTNAME=		aqsis-0.6.4
PKGREVISION=		4
CATEGORIES=		graphics
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=aqsis/}

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://www.aqsis.com/
COMMENT=		Renderman clone

GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes
LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig
USE_TOOLS+=		gmake
USE_X11=		yes

GCC_REQD+=		2.95.3
USE_LANGUAGES+=		c c++

.include "../../devel/libargparse/buildlink3.mk"
.include "../../graphics/Mesa/buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
