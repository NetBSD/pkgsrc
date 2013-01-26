# $NetBSD: Makefile,v 1.34 2013/01/26 21:38:24 adam Exp $

DISTNAME=		dvdauthor-0.7.0
PKGREVISION=		7
CATEGORIES=		multimedia
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=dvdauthor/}

MAINTAINER=		sekiya@NetBSD.org
HOMEPAGE=		http://dvdauthor.sourceforge.net/
COMMENT=		Tools to assist DVD authoring
LICENSE=		gnu-gpl-v2

WRKSRC=			${WRKDIR}/dvdauthor

GNU_CONFIGURE=		YES
USE_TOOLS+=		flex gmake yacc pkg-config
# To keep a consistent behavior with previous releases
CONFIGURE_ARGS+=	--enable-default-video-format=ntsc

.include "../../graphics/ImageMagick/buildlink3.mk"
.include "../../converters/fribidi/buildlink3.mk"
.include "../../multimedia/libdvdread/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
