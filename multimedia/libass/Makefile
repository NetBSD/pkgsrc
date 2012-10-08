# $NetBSD: Makefile,v 1.3 2012/10/08 09:21:05 asau Exp $
#

DISTNAME=	libass-0.9.12
PKGREVISION=	1
CATEGORIES=	multimedia
MASTER_SITES=	http://libass.googlecode.com/files/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://code.google.com/p/libass/
COMMENT=	Portable subtitle renderer for the ASS/SSA subtitle format
LICENSE=	isc

WRKSRC=		${WRKDIR}/libass-0.9.12
GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config

PKGCONFIG_OVERRIDE+=	libass.pc.in

.include "../../graphics/freetype2/buildlink3.mk"
.include "../../fonts/fontconfig/buildlink3.mk"
.include "../../textproc/enca/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
