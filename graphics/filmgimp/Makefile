# $NetBSD: Makefile,v 1.8 2004/04/24 22:46:10 jlam Exp $

DISTNAME=	filmgimp-0.15
PKGREVISION=	3
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=filmgimp/}

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://filmgimp.sourceforge.org/
COMMENT=	Motion picture editing tool

USE_BUILDLINK2=		yes
GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes

.include "../../devel/zlib/buildlink2.mk"
.include "../../graphics/png/buildlink2.mk"
.include "../../graphics/tiff/buildlink2.mk"
.include "../../x11/gtk/buildlink2.mk"

.include "../../mk/bsd.pkg.mk"
