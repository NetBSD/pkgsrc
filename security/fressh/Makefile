# $NetBSD: Makefile,v 1.12 2004/12/04 12:10:35 wiz Exp $

DISTNAME=		fressh-0.8.1
PKGREVISION=		2
CATEGORIES=		security
MASTER_SITES=		http://www.fressh.org/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://www.fressh.org/
COMMENT=		New, free, rewritten implementation of the SSH communication protocol

USE_BUILDLINK3=		yes

# Some versions of the openssl header files gives warnings.
BUILDLINK_TRANSFORM+=	rm:-Wstrict-prototypes
# too many unsigned char problems on -current
BUILDLINK_TRANSFORM+=	rm:-Werror

.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
