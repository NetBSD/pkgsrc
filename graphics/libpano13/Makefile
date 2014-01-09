# $NetBSD: Makefile,v 1.13 2014/01/09 10:40:18 jperkin Exp $

DISTNAME=	libpano13-2.9.18
PKGREVISION=	3
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=panotools/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://panotools.sourceforge.net/
COMMENT=	Cross-platform library behind Panorama Tools and other stitchers
LICENSE=	gnu-gpl-v2

USE_LANGUAGES=		c c++
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
PKGCONFIG_OVERRIDE=	libpano13.pc.in

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "SunOS" && empty(PKGSRC_COMPILER:Msunpro)
BUILDLINK_TRANSFORM+=	rm:-lsunmath
.endif

.include "../../mk/jpeg.buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
