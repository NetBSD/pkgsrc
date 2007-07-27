# $NetBSD: Makefile,v 1.16.6.1 2007/07/27 22:39:34 ghen Exp $
#

DISTNAME=	libarchive-1.3.1
PKGREVISION=	1
CATEGORIES=	archivers
MASTER_SITES=	http://people.freebsd.org/~kientzle/libarchive/src/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://people.freebsd.org/~kientzle/libarchive/src/
COMMENT=	Library to read/create different archive formats

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes

.include "../../archivers/bzip2/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
