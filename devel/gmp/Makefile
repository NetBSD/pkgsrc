# $NetBSD: Makefile,v 1.23 2003/10/28 22:33:57 kristerw Exp $
#

DISTNAME=		gmp-4.1.2
CATEGORIES=		devel
MASTER_SITES=		${MASTER_SITE_GNU:=gmp/}

MAINTAINER=		hubertf@NetBSD.org
HOMEPAGE=		http://www.gnu.org/software/gmp/gmp.html
COMMENT=		Library for arbitrary precision arithmetic

USE_BUILDLINK2=		YES
GNU_CONFIGURE=		YES
USE_GCC_SHLIB=		# defined
USE_GNU_TOOLS+=		m4
CONFIGURE_ARGS+=	--enable-cxx --without-readline
USE_LIBTOOL=		YES
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool

INFO_FILES=		gmp.info

TEST_TARGET=		check

.if ${MACHINE_ARCH} == "arm" || ${MACHINE_ARCH} == "arm32"
# The configure script thinks gcc 2.95 for ARM is too buggy to use.
GCC_REQD=		3.0
.endif

.include "../../mk/bsd.pkg.mk"
