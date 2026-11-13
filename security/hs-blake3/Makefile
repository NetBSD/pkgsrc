# $NetBSD: Makefile,v 1.2 2026/11/13 14:39:40 pho Exp $

DISTNAME=	blake3-0.3.1
PKGREVISION=	1
CATEGORIES=	security

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	BLAKE3 hashing algorithm
LICENSE=	apache-2.0

.include "../../mk/bsd.prefs.mk"
.if ${MACHINE_ARCH} == "aarch64" || ${MACHINE_ARCH:M*arm*}
# We can delete this line when the upstream makes a new release containing
# this: https://github.com/k0001/hs-blake3/pull/10
CONFIGURE_ARGS+=	-f-avx512 -f-avx2 -f-sse41 -f-sse2
.endif

.include "../../devel/hs-ram/buildlink3.mk"
.include "../../mk/haskell.mk"
.include "../../mk/bsd.pkg.mk"
