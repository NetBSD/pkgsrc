# $NetBSD: Makefile,v 1.13 2017/02/27 12:30:47 wiz Exp $

DISTNAME=	potrace-1.14
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
