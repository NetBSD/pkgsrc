# $NetBSD: Makefile,v 1.25 2004/01/19 13:15:52 jlam Exp $
#

DISTNAME=		gmp-4.1.2
CATEGORIES=		devel math
MASTER_SITES=		${MASTER_SITE_GNU:=gmp/}

MAINTAINER=		hubertf@NetBSD.org
HOMEPAGE=		http://www.gnu.org/software/gmp/gmp.html
COMMENT=		Library for arbitrary precision arithmetic

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_BUILDLINK3=		YES
GNU_CONFIGURE=		YES
USE_GCC_SHLIB=		YES
USE_LIBTOOL=		YES
USE_GNU_TOOLS+=		m4

LIBTOOL_OVERRIDE=	${WRKSRC}/libtool

CONFIGURE_ARGS+=	--enable-cxx --without-readline

INFO_FILES=		gmp.info

TEST_TARGET=		check

.if ${MACHINE_ARCH} == "arm" || ${MACHINE_ARCH} == "arm32"
# The configure script thinks gcc 2.95 for ARM is too buggy to use.
GCC_REQD=		3.0
.endif

.include "../../mk/bsd.pkg.mk"
