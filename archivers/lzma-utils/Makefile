# $NetBSD: Makefile,v 1.3 2009/06/08 14:01:58 wiz Exp $
#

DISTNAME=	lzma-4.32.7
PKGNAME=	lzma-utils-4.32.7
CATEGORIES=	archivers
MASTER_SITES=	http://tukaani.org/lzma/

MAINTAINER=	magnus.henoch@gmail.com
HOMEPAGE=	http://tukaani.org/lzma/
COMMENT=	LZMA compression and decompression utilities

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_LANGUAGES=	c c++

CONFLICTS=	lzma-[0-9]* xz-utils-[0-9]*

.include "../../mk/bsd.pkg.mk"
