# $NetBSD: Makefile,v 1.11 2004/11/18 15:51:35 jlam Exp $
#

DISTNAME=	mm-1.2.2
PKGNAME=	lib${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	ftp://ftp.ossp.org/pkg/lib/mm/

MAINTAINER=	cjones@NetBSD.org
HOMEPAGE=	http://www.ossp.org/pkg/lib/mm/
COMMENT=	Portable abstraction layer for shared memory

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_BUILDLINK3=		YES
GNU_CONFIGURE=		YES
USE_LIBTOOL=		YES
TEST_TARGET=		test

.include "../../mk/bsd.pkg.mk"
