# $NetBSD: Makefile,v 1.14 2018/11/08 14:40:20 kleink Exp $

DISTNAME=	potrace-1.15
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

.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
