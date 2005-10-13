# $NetBSD: Makefile,v 1.9 2005/10/13 21:34:16 xtraeme Exp $
#

DISTNAME=	libarchive-1.02.036
CATEGORIES=	archivers
MASTER_SITES=	http://people.freebsd.org/~kientzle/libarchive/src/

MAINTAINER=	xtraeme@NetBSD.org
HOMEPAGE=	http://people.freebsd.org/~kientzle/libarchive/src/
COMMENT=	Library to read/create different archive formats

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes

.include "../../archivers/bzip2/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
