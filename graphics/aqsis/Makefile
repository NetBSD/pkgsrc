# $NetBSD: Makefile,v 1.5 2003/06/02 14:05:04 abs Exp $
#

DISTNAME=		aqsis-0.6.4
PKGREVISION=		1
CATEGORIES=		graphics
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=aqsis/}

MAINTAINER=		tech-pkg@netbsd.org
HOMEPAGE=		http://www.aqsis.org/
COMMENT=		Renderman clone

GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes
LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig
USE_GMAKE=		yes
USE_X11=		yes

USE_BUILDLINK2=		yes

.include "../../mk/gcc.buildlink2.mk"
.include "../../devel/libargparse/buildlink2.mk"
.include "../../graphics/Mesa/buildlink2.mk"
.include "../../graphics/tiff/buildlink2.mk"

.include "../../mk/bsd.pkg.mk"
