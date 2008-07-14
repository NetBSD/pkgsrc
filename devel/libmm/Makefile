# $NetBSD: Makefile,v 1.18 2008/07/14 12:56:02 joerg Exp $

DISTNAME=	mm-1.4.2
PKGNAME=	lib${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	ftp://ftp.ossp.org/pkg/lib/mm/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.ossp.org/pkg/lib/mm/
COMMENT=	Portable abstraction layer for shared memory

PKG_INSTALLATION_TYPES=	overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=		YES
USE_LIBTOOL=		YES
TEST_TARGET=		test

.include "../../mk/bsd.pkg.mk"
