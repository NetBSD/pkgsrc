# $NetBSD: Makefile,v 1.47 2016/03/05 11:28:59 jperkin Exp $

DISTNAME=		dvdauthor-0.7.1
PKGREVISION=		9
CATEGORIES=		multimedia
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=dvdauthor/}

MAINTAINER=		pkgsrc-users@NetBSD.org
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
