# $NetBSD: Makefile,v 1.1.1.1 2004/01/12 15:55:11 drochner Exp $
#

DISTNAME=		lsh-1.4.3
CATEGORIES=		security
MASTER_SITES=		ftp://ftp.lysator.liu.se/pub/security/lsh/

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://www.lysator.liu.se/~nisse/lsh/
COMMENT=		ssh2 client/server

USE_BUILDLINK2=		yes
GNU_CONFIGURE=		yes
USE_GMAKE=		yes

.include "../../devel/gmp/buildlink2.mk"
.include "../../devel/liboop/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
