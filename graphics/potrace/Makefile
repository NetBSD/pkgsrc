# $NetBSD: Makefile,v 1.17 2022/07/01 16:15:47 adam Exp $

DISTNAME=	potrace-1.16
CATEGORIES=	graphics
MASTER_SITES=	http://potrace.sourceforge.net/download/
MASTER_SITES+=	${MASTER_SITE_SOURCEFORGE:=potrace/}

MAINTAINER=	adam@NetBSD.org
HOMEPAGE=	http://potrace.sourceforge.net/
COMMENT=	Utility for transforming bitmaps into vector graphics
LICENSE=	gnu-gpl-v2

USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--with-libpotrace
TEST_TARGET=		check

.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
