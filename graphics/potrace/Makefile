# $NetBSD: Makefile,v 1.8 2012/10/06 14:11:15 asau Exp $

DISTNAME=	potrace-1.10
PKGREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	http://potrace.sourceforge.net/download/ \
		${MASTER_SITE_SOURCEFORGE:=potrace/}

MAINTAINER=	adam@NetBSD.org
HOMEPAGE=	http://potrace.sourceforge.net/
COMMENT=	Utility for transforming bitmaps into vector graphics
LICENSE=	gnu-gpl-v2

USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes

.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
