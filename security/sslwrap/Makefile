# $NetBSD: Makefile,v 1.6.2.1 2002/06/30 06:24:09 jlam Exp $
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
