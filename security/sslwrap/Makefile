# $NetBSD: Makefile,v 1.10 2003/09/18 04:09:17 jmc Exp $
#

DISTNAME=	${PKGNAME:S/-//}
PKGNAME=	sslwrap-206
CATEGORIES=	security net
MASTER_SITES=	http://www.rickk.com/sslwrap/

MAINTAINER=	rh@NetBSD.org
HOMEPAGE=	http://www.rickk.com/sslwrap/
COMMENT=	Simple SSL wrapper

USE_BUILDLINK2=	YES

.include "../../security/openssl/buildlink2.mk"

.if !exists(${BUILDLINK_PREFIX.openssl}/include/openssl/e_os.h)
CFLAGS+=	-DFLAT_INC
.endif

.include "../../mk/bsd.pkg.mk"
