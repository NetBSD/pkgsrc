# $NetBSD: Makefile,v 1.1.1.1 2004/06/25 06:58:42 sekiya Exp $

DISTNAME=		dvdauthor-0.6.10
CATEGORIES=		multimedia
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=dvdauthor/}

MAINTAINER=		sekiya@NetBSD.org
HOMEPAGE=		http://dvdauthor.sourceforge.net/
COMMENT=		Tools to assist DVD authoring

USE_BUILDLINK3=		YES
GNU_CONFIGURE=		YES
USE_GNU_TOOLS=		make

.include "../../graphics/ImageMagick/buildlink3.mk"
.include "../../converters/fribidi/buildlink3.mk"
.include "../libdvdread/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
