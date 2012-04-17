# $NetBSD: Makefile,v 1.7 2012/04/17 21:56:52 wiz Exp $

DISTNAME=	potrace-1.10
PKGREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	http://potrace.sourceforge.net/download/ \
		${MASTER_SITE_SOURCEFORGE:=potrace/}

MAINTAINER=	adam@NetBSD.org
HOMEPAGE=	http://potrace.sourceforge.net/
COMMENT=	Utility for transforming bitmaps into vector graphics
LICENSE=	gnu-gpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes

.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
