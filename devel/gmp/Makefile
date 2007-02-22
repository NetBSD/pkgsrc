# $NetBSD: Makefile,v 1.43 2007/02/22 19:01:17 wiz Exp $

DISTNAME=	gmp-4.2.1
CATEGORIES=	devel math
MASTER_SITES=	${MASTER_SITE_GNU:=gmp/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://swox.com/gmp/
COMMENT=	Library for arbitrary precision arithmetic

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_LANGUAGES=		c c++ c99
USE_TOOLS+=		gm4
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--enable-cxx --without-readline
INFO_FILES=		# PLIST

TEST_TARGET=		check

.include "../../mk/bsd.prefs.mk"
.if !empty(LOWER_OPSYS:Mirix5*) && !empty(ABI)
ABI=			o32
.endif

.if ${MACHINE_ARCH} == "arm" || ${MACHINE_ARCH} == "arm32"
# The configure script thinks gcc 2.95 for ARM is too buggy to use.
GCC_REQD+=		3.0
.endif

.include "../../mk/bsd.pkg.mk"
