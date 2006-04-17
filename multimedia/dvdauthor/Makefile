# $NetBSD: Makefile,v 1.9 2006/04/17 13:46:41 wiz Exp $

DISTNAME=		dvdauthor-0.6.10
PKGREVISION=	5
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
