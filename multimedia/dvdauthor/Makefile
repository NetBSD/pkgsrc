# $NetBSD: Makefile,v 1.2 2004/10/03 00:13:01 tv Exp $

DISTNAME=		dvdauthor-0.6.10
PKGREVISION=	1
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
