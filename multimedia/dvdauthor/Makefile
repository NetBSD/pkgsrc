# $NetBSD: Makefile,v 1.10 2006/08/08 19:07:14 minskim Exp $

DISTNAME=		dvdauthor-0.6.10
PKGREVISION=	5
CATEGORIES=		multimedia
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=dvdauthor/}

MAINTAINER=		sekiya@NetBSD.org
HOMEPAGE=		http://dvdauthor.sourceforge.net/
COMMENT=		Tools to assist DVD authoring

GNU_CONFIGURE=		YES
USE_TOOLS+=		flex gmake yacc

.include "../../graphics/ImageMagick/buildlink3.mk"
.include "../../converters/fribidi/buildlink3.mk"
.include "../../multimedia/libdvdread/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
