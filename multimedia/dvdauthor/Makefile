# $NetBSD: Makefile,v 1.18 2009/08/26 21:20:14 sno Exp $

DISTNAME=		dvdauthor-0.6.14
PKGREVISION=		3
CATEGORIES=		multimedia
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=dvdauthor/}

MAINTAINER=		sekiya@NetBSD.org
HOMEPAGE=		http://dvdauthor.sourceforge.net/
COMMENT=		Tools to assist DVD authoring

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=		YES
USE_TOOLS+=		flex gmake yacc

.include "../../graphics/ImageMagick/buildlink3.mk"
.include "../../converters/fribidi/buildlink3.mk"
.include "../../multimedia/libdvdread/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
