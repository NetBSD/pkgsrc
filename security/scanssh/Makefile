# $NetBSD: Makefile,v 1.12 2004/06/27 11:42:43 grant Exp $

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
