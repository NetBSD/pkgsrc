# $NetBSD: Makefile,v 1.5 2005/05/22 20:08:18 jlam Exp $

DISTNAME=		dvdauthor-0.6.10
PKGREVISION=	2
CATEGORIES=		multimedia
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=dvdauthor/}

MAINTAINER=		sekiya@NetBSD.org
HOMEPAGE=		http://dvdauthor.sourceforge.net/
COMMENT=		Tools to assist DVD authoring

GNU_CONFIGURE=		YES
USE_TOOLS=		gmake

.include "../../graphics/ImageMagick/buildlink3.mk"
.include "../../converters/fribidi/buildlink3.mk"
.include "../libdvdread/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
