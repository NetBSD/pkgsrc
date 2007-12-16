# $NetBSD: Makefile,v 1.5 2007/12/16 00:08:27 tron Exp $

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

.include "../../mk/bsd.prefs.mk"

.if !empty(MACHINE_PLATFORM:MDarwin-[9].*-i386)
CONFIGURE_ARGS+=	--disable-asm
.endif

.include "../../mk/bsd.pkg.mk"
