# $NetBSD: Makefile,v 1.6 2001/07/27 14:46:10 jlam Exp $
#

DISTNAME=	${PKGNAME:S/-//}
PKGNAME=	sslwrap-206
CATEGORIES=	security net
MASTER_SITES=	http://www.rickk.com/sslwrap/

MAINTAINER=	rh@netbsd.org
HOMEPAGE=	http://www.rickk.com/sslwrap/
COMMENT=	simple ssl wrapper

USE_BUILDLINK_ONLY=	YES

.include "../../security/openssl/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
