# $NetBSD: Makefile,v 1.30 2012/02/06 12:41:01 wiz Exp $

DISTNAME=		dvdauthor-0.7.0
PKGREVISION=		4
CATEGORIES=		multimedia
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=dvdauthor/}

MAINTAINER=		sekiya@NetBSD.org
HOMEPAGE=		http://dvdauthor.sourceforge.net/
COMMENT=		Tools to assist DVD authoring
LICENSE=		gnu-gpl-v2

WRKSRC=			${WRKDIR}/dvdauthor

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=		YES
USE_TOOLS+=		flex gmake yacc pkg-config
# To keep a consistent behavior with previous releases
CONFIGURE_ARGS+=	--enable-default-video-format=ntsc

.include "../../graphics/ImageMagick/buildlink3.mk"
.include "../../converters/fribidi/buildlink3.mk"
.include "../../multimedia/libdvdread/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
