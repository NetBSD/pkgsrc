# $NetBSD: Makefile,v 1.3 2006/05/01 20:46:54 adam Exp $

DISTNAME=	potrace-1.7
CATEGORIES=	graphics
MASTER_SITES=	http://potrace.sourceforge.net/download/ \
		${MASTER_SITE_SOURCEFORGE:=potrace/}

MAINTAINER=	adam@NetBSD.org
HOMEPAGE=	http://potrace.sourceforge.net/
COMMENT=	Utility for transforming bitmaps into vector graphics

USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes

.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
