# $NetBSD: Makefile,v 1.11.4.1 2004/07/26 16:33:41 agc Exp $

DISTNAME=	scanssh-1.6b
CATEGORIES=	security
MASTER_SITES=	http://monkey.org/~provos/				\
		ftp://ftp.openbsd.org/pub/OpenBSD/OpenSSH/scanssh/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://monkey.org/~provos/scanssh/
COMMENT=	SSH remote version scanner

WRKSRC=		${WRKDIR}/scanssh
GNU_CONFIGURE=	yes
USE_BUILDLINK3=	yes

.include "../../net/libpcap/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
