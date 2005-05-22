# $NetBSD: Makefile,v 1.9 2005/05/22 20:08:30 jlam Exp $
#

DISTNAME=		lsh-1.4.3
PKGREVISION=	2
CATEGORIES=		security
MASTER_SITES=		ftp://ftp.lysator.liu.se/pub/security/lsh/

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://www.lysator.liu.se/~nisse/lsh/
COMMENT=		ssh2 client/server

GNU_CONFIGURE=		yes
USE_TOOLS+=		gmake

.include "../../devel/gmp/buildlink3.mk"
.include "../../devel/liboop/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
