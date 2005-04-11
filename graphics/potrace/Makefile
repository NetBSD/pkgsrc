# $NetBSD: Makefile,v 1.2 2005/04/11 21:46:08 tv Exp $

DISTNAME=	potrace-1.5
CATEGORIES=	graphics
MASTER_SITES=	http://potrace.sourceforge.net/download/ \
		${MASTER_SITE_SOURCEFORGE:=potrace/}

MAINTAINER=	adam@NetBSD.org
HOMEPAGE=	http://potrace.sourceforge.net/
COMMENT=	Utility for transforming bitmaps into vector graphics

GNU_CONFIGURE=		yes

.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
