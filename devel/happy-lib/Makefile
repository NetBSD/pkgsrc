# $NetBSD: Makefile,v 1.8 2025/08/13 11:06:27 pho Exp $

DISTNAME=	happy-lib-2.1.6
PKGNAME=	${DISTNAME}
PKGREVISION=	2
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Library for the happy parser generator for Haskell
LICENSE=	2-clause-bsd

# 2025-08, NetBSD 10 amd64:
#   => Checking for missing run-time search paths in happy-lib-2.1.6nb1
#   ERROR: lib/x86_64-netbsd-ghc-9.10.1/libHShappy-lib-2.1.6-9AfrUwe9Qv1If9y7GwKbDL-backend-lalr-ghc9.10.1.so: rpath relative to WRKDIR
#   ERROR: lib/x86_64-netbsd-ghc-9.10.1/libHShappy-lib-2.1.6-9AfrUwe9Qv1If9y7GwKbDL-backend-lalr-ghc9.10.1.so: rpath relative to WRKDIR
#   ERROR: lib/x86_64-netbsd-ghc-9.10.1/libHShappy-lib-2.1.6-3VQ51JeezbZF3Yr8Ycn9ut-tabular-ghc9.10.1.so: rpath relative to WRKDIR
#   ERROR: lib/x86_64-netbsd-ghc-9.10.1/libHShappy-lib-2.1.6-5o1JMIdVudi9OuEUdqJGfN-backend-glr-ghc9.10.1.so: rpath relative to WRKDIR
#   *** Error code 1
# In lieu of fixing upstream, hack around this.
BUILDLINK_TRANSFORM+=	rm:-Wl,-rpath,${WRKSRC}/dist/build/backend-glr
BUILDLINK_TRANSFORM+=	rm:-Wl,-rpath,${WRKSRC}/dist/build/frontend

.include "../../mk/haskell.mk"
.include "../../mk/bsd.pkg.mk"
