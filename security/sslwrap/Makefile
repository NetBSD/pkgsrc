# $NetBSD: Makefile,v 1.7 2002/08/25 21:50:44 jlam Exp $
#

DISTNAME=	${PKGNAME:S/-//}
PKGNAME=	sslwrap-206
CATEGORIES=	security net
MASTER_SITES=	http://www.rickk.com/sslwrap/

MAINTAINER=	rh@netbsd.org
HOMEPAGE=	http://www.rickk.com/sslwrap/
COMMENT=	simple ssl wrapper

USE_BUILDLINK2=	YES

.include "../../security/openssl/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
