# $NetBSD: Makefile,v 1.3 2005/02/14 08:20:10 xtraeme Exp $
#

DISTNAME=	libarchive-1.02.006
CATEGORIES=	archivers
MASTER_SITES=	http://people.freebsd.org/~kientzle/libarchive/src/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://people.freebsd.org/~kientzle/libarchive/src/
COMMENT=	Library to read/create different archive formats

USE_BUILDLINK3=	yes
GNU_CONFIGURE=	yes

.include "../../archivers/bzip2/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
