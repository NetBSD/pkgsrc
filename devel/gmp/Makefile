# $NetBSD: Makefile,v 1.21 2003/09/17 16:24:37 grant Exp $
#

DISTNAME=		gmp-4.1.2
CATEGORIES=		devel
MASTER_SITES=		${MASTER_SITE_GNU:=gmp/}

MAINTAINER=		hubertf@NetBSD.org
HOMEPAGE=		http://www.gnu.org/software/gmp/gmp.html
COMMENT=		Library for arbitrary precision arithmetic

BUILD_DEPENDS+=		m4>=1.4:../../devel/m4

USE_BUILDLINK2=		YES
GNU_CONFIGURE=		YES
CONFIGURE_ARGS+=	--enable-cxx --without-readline
USE_LIBTOOL=		YES
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool
USE_GCC_SHLIB=		# defined

INFO_FILES=		gmp.info
M4=			${PREFIX}/bin/gm4

TEST_TARGET=		check

.include "../../mk/bsd.pkg.mk"
