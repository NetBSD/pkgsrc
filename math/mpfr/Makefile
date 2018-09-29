# $NetBSD: Makefile,v 1.39 2018/09/29 16:37:09 sevan Exp $

DISTNAME=		mpfr-4.0.1
CATEGORIES=		math
MASTER_SITES=		http://www.mpfr.org/${DISTNAME}/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.mpfr.org/
COMMENT=		GMP-based library for multiple-precision floating-point computations
LICENSE=		gnu-lgpl-v3

.include "../../mk/bsd.prefs.mk"
GNU_CONFIGURE=		yes
.if !empty(MACHINE_PLATFORM:MNetBSD-[0-8]*-*) || !empty(MACHINE_PLATFORM:MDragonFly-[0-5]*-*)
CONFIGURE_ARGS+=        --disable-float128
.endif
USE_LIBTOOL=		yes
TEST_TARGET=		check
INFO_FILES=		yes

PKGCONFIG_OVERRIDE+=	mpfr.pc.in

BUILDLINK_API_DEPENDS.gmp+=	gmp>=5.0
.include "../../devel/gmp/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"

.if (${MACHINE_ARCH} == alpha)
CONFIGURE_ENV+=CFLAGS="${CFLAGS:N-mieee}"
.endif
