# $NetBSD: Makefile,v 1.10 2005/12/27 22:28:33 reed Exp $
#

DISTNAME=		lsh-1.4.3
PKGREVISION=	2
CATEGORIES=		security
MASTER_SITES=		ftp://ftp.lysator.liu.se/pub/security/lsh/

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://www.lysator.liu.se/~nisse/lsh/
COMMENT=		SSH2 client/server (version 1 of lsh)

GNU_CONFIGURE=		yes
USE_TOOLS+=		gmake

.include "../../devel/gmp/buildlink3.mk"
.include "../../devel/liboop/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
