# $NetBSD: Makefile,v 1.15 2006/03/04 21:30:34 jlam Exp $

DISTNAME=		fressh-0.8.1
PKGREVISION=		3
CATEGORIES=		security
MASTER_SITES=		http://www.fressh.org/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.fressh.org/
COMMENT=		New, free, rewritten implementation of the SSH communication protocol

USE_OLD_DES_API=	yes

# Some versions of the openssl header files gives warnings.
BUILDLINK_TRANSFORM+=	rm:-Wstrict-prototypes
# too many unsigned char problems on -current
BUILDLINK_TRANSFORM+=	rm:-Werror

.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
