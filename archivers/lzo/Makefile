# $NetBSD: Makefile,v 1.9 2010/02/19 20:16:40 heinz Exp $

DISTNAME=	lzo-2.03
CATEGORIES=	archivers
MASTER_SITES=	http://ftp.uni-koeln.de/util/arc/ \
		http://www.oberhumer.com/opensource/lzo/download/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.oberhumer.com/opensource/lzo/
COMMENT=	Portable lossless data compression library
LICENSE=	gnu-gpl-v2

PKG_INSTALLATION_TYPES=	overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	YES
USE_LIBTOOL=	YES
TEST_TARGET=	test

.include "../../mk/bsd.prefs.mk"

.if !empty(MACHINE_PLATFORM:MDarwin-9.*-i386) || \
    !empty(MACHINE_PLATFORM:MDarwin-??.*-*)
CONFIGURE_ARGS+=	--disable-asm
.endif

.include "../../mk/bsd.pkg.mk"
