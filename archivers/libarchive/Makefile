# $NetBSD: Makefile,v 1.12 2006/05/01 09:02:38 xtraeme Exp $
#

DISTNAME=	libarchive-1.2.53
CATEGORIES=	archivers
MASTER_SITES=	http://people.freebsd.org/~kientzle/libarchive/src/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://people.freebsd.org/~kientzle/libarchive/src/
COMMENT=	Library to read/create different archive formats

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes

.include "../../archivers/bzip2/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
