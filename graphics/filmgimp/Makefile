# $NetBSD: Makefile,v 1.4 2003/07/17 21:40:30 grant Exp $

DISTNAME=	filmgimp-0.15
PKGREVISION=	2
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=filmgimp/}

MAINTAINER=	jlam@NetBSD.org
HOMEPAGE=	http://filmgimp.sourceforge.org/
COMMENT=	motion picture editing tool

USE_BUILDLINK2=		yes
GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool

.include "../../devel/zlib/buildlink2.mk"
.include "../../graphics/png/buildlink2.mk"
.include "../../graphics/tiff/buildlink2.mk"
.include "../../x11/gtk/buildlink2.mk"

.include "../../mk/bsd.pkg.mk"
