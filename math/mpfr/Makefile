# $NetBSD: Makefile,v 1.46 2022/11/27 03:17:13 mef Exp $

DISTNAME=	mpfr-4.1.1
PKGREVISION=	1
CATEGORIES=	math
MASTER_SITES=	http://www.mpfr.org/${DISTNAME}/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.mpfr.org/
COMMENT=	GMP-based library for multiple-precision floating-point computations
LICENSE=	gnu-lgpl-v3

USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
.include "../../mk/bsd.prefs.mk"
.if !empty(MACHINE_PLATFORM:MNetBSD-[0-9]*-*) || !empty(MACHINE_PLATFORM:MDragonFly-[0-5]*-*)
CONFIGURE_ARGS+=        --disable-float128
.endif
TEST_TARGET=		check
INFO_FILES=		yes

PKGCONFIG_OVERRIDE+=	mpfr.pc.in

BUILDLINK_API_DEPENDS.gmp+=	gmp>=5.0
.include "../../devel/gmp/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"

.if (${MACHINE_ARCH} == alpha)
CONFIGURE_ENV+=	CFLAGS="${CFLAGS:N-mieee}"
.endif
