# $NetBSD: Makefile,v 1.12 2003/01/10 17:33:53 jmmv Exp $
#

DISTNAME=	autotrace-0.31.1
CATEGORIES=	graphics cad
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=autotrace/}

MAINTAINER=	rh@netbsd.org
HOMEPAGE=	http://autotrace.sourceforge.net/
COMMENT=	convert bitmap to vector graphics

USE_BUILDLINK2=		YES
USE_X11=		YES
GNU_CONFIGURE=		YES

PKGCONFIG_OVERRIDE=	${WRKSRC}/autotrace.pc.in

.include "../../graphics/ImageMagick/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
