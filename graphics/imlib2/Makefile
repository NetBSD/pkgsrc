# $NetBSD: Makefile,v 1.36 2005/12/05 20:50:20 rillig Exp $

DISTNAME=	imlib2-1.2.0
PKGREVISION=	3
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=enlightenment/}

MAINTAINER=	rh@NetBSD.org
HOMEPAGE=	http://www.enlightenment.org/pages/imlib2.html
COMMENT=	Image manipulation library

USE_TOOLS+=		pkg-config
USE_LIBTOOL=		YES
GNU_CONFIGURE=		YES

PKGCONFIG_OVERRIDE=	imlib2.pc.in

LIBS.SunOS+=		-lm

.include "options.mk"

.include "../../archivers/bzip2/buildlink3.mk"
.include "../../devel/libltdl/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../graphics/jpeg/buildlink3.mk"
.include "../../graphics/libungif/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"
.include "../../mk/x11.buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
