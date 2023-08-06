# $NetBSD: Makefile,v 1.25 2023/08/06 11:06:13 adam Exp $

DISTNAME=	libpano13-2.9.21
PKGREVISION=	2
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=panotools/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://panotools.sourceforge.net/
COMMENT=	Cross-platform library behind Panorama Tools and other stitchers
LICENSE=	gnu-gpl-v2

MAKE_JOBS_SAFE=		no

USE_LANGUAGES=		c c++
USE_TOOLS+=		gmake pod2man
TOOLS_BROKEN+=		perl
PKGCONFIG_OVERRIDE=	libpano13.pc.in

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "SunOS" && empty(PKGSRC_COMPILER:Msunpro)
BUILDLINK_TRANSFORM+=	rm:-lsunmath
.endif

.include "../../devel/cmake/build.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"
.include "../../mk/jpeg.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
