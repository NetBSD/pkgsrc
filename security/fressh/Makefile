# $NetBSD: Makefile,v 1.13 2004/12/15 19:34:40 jlam Exp $

DISTNAME=		fressh-0.8.1
PKGREVISION=		3
CATEGORIES=		security
MASTER_SITES=		http://www.fressh.org/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://www.fressh.org/
COMMENT=		New, free, rewritten implementation of the SSH communication protocol

USE_BUILDLINK3=		yes
USE_OLD_DES_API=	yes

# Some versions of the openssl header files gives warnings.
BUILDLINK_TRANSFORM+=	rm:-Wstrict-prototypes
# too many unsigned char problems on -current
BUILDLINK_TRANSFORM+=	rm:-Werror

.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
