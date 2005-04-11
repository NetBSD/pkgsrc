# $NetBSD: Makefile,v 1.4 2005/04/11 21:46:41 tv Exp $

DISTNAME=		dvdauthor-0.6.10
PKGREVISION=	2
CATEGORIES=		multimedia
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=dvdauthor/}

MAINTAINER=		sekiya@NetBSD.org
HOMEPAGE=		http://dvdauthor.sourceforge.net/
COMMENT=		Tools to assist DVD authoring

GNU_CONFIGURE=		YES
USE_GNU_TOOLS=		make

.include "../../graphics/ImageMagick/buildlink3.mk"
.include "../../converters/fribidi/buildlink3.mk"
.include "../libdvdread/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
