# $NetBSD: Makefile,v 1.10 2017/01/19 18:52:12 agc Exp $

DISTNAME=	potrace-1.11
CATEGORIES=	graphics
MASTER_SITES=	http://potrace.sourceforge.net/download/
MASTER_SITES+=	${MASTER_SITE_SOURCEFORGE:=potrace/}

MAINTAINER=	adam@NetBSD.org
HOMEPAGE=	http://potrace.sourceforge.net/
COMMENT=	Utility for transforming bitmaps into vector graphics
LICENSE=	gnu-gpl-v2

USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes

.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
