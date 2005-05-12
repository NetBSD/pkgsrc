# $NetBSD: Makefile,v 1.5.4.1 2005/05/12 22:36:02 snj Exp $
#

DISTNAME=		lsh-1.4.3
PKGREVISION=	2
CATEGORIES=		security
MASTER_SITES=		ftp://ftp.lysator.liu.se/pub/security/lsh/

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://www.lysator.liu.se/~nisse/lsh/
COMMENT=		ssh2 client/server

USE_BUILDLINK3=		yes
GNU_CONFIGURE=		yes
USE_GNU_TOOLS+=		make

.include "../../devel/gmp/buildlink3.mk"
.include "../../devel/liboop/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
