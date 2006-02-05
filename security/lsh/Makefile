# $NetBSD: Makefile,v 1.11 2006/02/05 23:10:45 joerg Exp $
#

DISTNAME=		lsh-1.4.3
PKGREVISION=	3
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
