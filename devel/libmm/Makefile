# $NetBSD: Makefile,v 1.12 2004/11/25 14:19:06 adam Exp $

DISTNAME=	mm-1.3.1
PKGNAME=	lib${DISTNAME}
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
