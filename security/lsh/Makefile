# $NetBSD: Makefile,v 1.2 2004/02/14 15:10:27 uebayasi Exp $
#

DISTNAME=		lsh-1.4.3
CATEGORIES=		security
MASTER_SITES=		ftp://ftp.lysator.liu.se/pub/security/lsh/

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://www.lysator.liu.se/~nisse/lsh/
COMMENT=		ssh2 client/server

USE_BUILDLINK2=		yes
GNU_CONFIGURE=		yes
USE_GNU_TOOLS=		make

.include "../../devel/gmp/buildlink2.mk"
.include "../../devel/liboop/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
