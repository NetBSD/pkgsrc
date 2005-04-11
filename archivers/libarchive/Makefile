# $NetBSD: Makefile,v 1.6 2005/04/11 21:44:49 tv Exp $
#

DISTNAME=	libarchive-1.02.016
CATEGORIES=	archivers
MASTER_SITES=	http://people.freebsd.org/~kientzle/libarchive/src/

MAINTAINER=	xtraeme@NetBSD.org
HOMEPAGE=	http://people.freebsd.org/~kientzle/libarchive/src/
COMMENT=	Library to read/create different archive formats

GNU_CONFIGURE=	yes

.include "../../archivers/bzip2/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
