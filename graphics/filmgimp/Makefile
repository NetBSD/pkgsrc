# $NetBSD: Makefile,v 1.10 2004/04/25 02:01:20 minskim Exp $

DISTNAME=	filmgimp-0.15
PKGREVISION=	3
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=filmgimp/}

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://filmgimp.sourceforge.org/
COMMENT=	Motion picture editing tool

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_BUILDLINK3=		yes
GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes

.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"
.include "../../x11/gtk/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
