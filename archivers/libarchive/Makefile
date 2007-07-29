# $NetBSD: Makefile,v 1.18 2007/07/29 17:35:14 joerg Exp $
#

DISTNAME=	libarchive-2.2.5
CATEGORIES=	archivers
MASTER_SITES=	http://people.freebsd.org/~kientzle/libarchive/src/

MAINTAINER=	joerg@NetBSD.org
HOMEPAGE=	http://people.freebsd.org/~kientzle/libarchive/
COMMENT=	Library to read/create different archive formats

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes

.include "../../archivers/bzip2/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
