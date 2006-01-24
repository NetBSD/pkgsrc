# $NetBSD: Makefile,v 1.7 2006/01/24 07:32:26 wiz Exp $

DISTNAME=		dvdauthor-0.6.10
PKGREVISION=	3
CATEGORIES=		multimedia
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=dvdauthor/}

MAINTAINER=		sekiya@NetBSD.org
HOMEPAGE=		http://dvdauthor.sourceforge.net/
COMMENT=		Tools to assist DVD authoring

GNU_CONFIGURE=		YES
USE_TOOLS+=		gmake

.include "../../graphics/ImageMagick/buildlink3.mk"
.include "../../converters/fribidi/buildlink3.mk"
.include "../../multimedia/libdvdread/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
