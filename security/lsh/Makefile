# $NetBSD: Makefile,v 1.14 2006/06/16 18:43:18 jlam Exp $
#

DISTNAME=		lsh-1.4.3
PKGREVISION=		5
CATEGORIES=		security
MASTER_SITES=		ftp://ftp.lysator.liu.se/pub/security/lsh/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.lysator.liu.se/~nisse/lsh/
COMMENT=		SSH2 client/server (version 1 of lsh)

GNU_CONFIGURE=		yes
USE_TOOLS+=		gmake

.include "options.mk"

.include "../../devel/gmp/buildlink3.mk"
.include "../../devel/liboop/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
