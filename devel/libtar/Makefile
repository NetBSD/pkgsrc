# $NetBSD: Makefile,v 1.1.1.1 2002/04/22 17:14:48 seb Exp $
#

DISTNAME=	libtar-1.2.5
CATEGORIES=	devel archivers
MASTER_SITES=	ftp://ftp-dev.cso.uiuc.edu/pub/libtar/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www-dev.cso.uiuc.edu/libtar/
COMMENT=	library for manipulating POSIX tar files

GNU_CONFIGURE=		YES
USE_BUILDLINK_ONLY=	YES

.include "../../devel/zlib/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
