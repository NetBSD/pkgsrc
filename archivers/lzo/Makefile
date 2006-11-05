# $NetBSD: Makefile,v 1.4 2006/11/05 17:10:43 joerg Exp $
#

DISTNAME=	lzo-2.02
CATEGORIES=	archivers
MASTER_SITES=	http://ftp.uni-koeln.de/util/arc/ \
		http://www.oberhumer.com/opensource/lzo/download/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.oberhumer.com/opensource/lzo/
COMMENT=	Portable lossless data compression library

PKG_INSTALLATION_TYPES=	overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	YES
USE_LIBTOOL=	YES
TEST_TARGET=	test

.include "../../mk/bsd.pkg.mk"
