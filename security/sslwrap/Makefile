# $NetBSD: Makefile,v 1.11 2003/11/12 03:39:43 jschauma Exp $
#

DISTNAME=	${PKGNAME:S/-//}
PKGNAME=	sslwrap-206
PKGREVISION=	1
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
