# $NetBSD: Makefile,v 1.14 2007/07/14 14:03:06 heinz Exp $

DISTNAME=		dvdauthor-0.6.13
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
