# $NetBSD: Makefile,v 1.15 2010/01/17 12:02:06 wiz Exp $

DISTNAME=	postal-0.62
PKGREVISION=	5
CATEGORIES=	benchmarks
MASTER_SITES=	http://www.coker.com.au/postal/
EXTRACT_SUFX=	.tgz

MAINTAINER=	david@silicium.ath.cx
HOMEPAGE=	http://www.coker.com.au/postal/
COMMENT=	Tool for benchmarking SMTP/POP servers

PKG_INSTALLATION_TYPES=	overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes
USE_LANGUAGES=	c c++
USE_TOOLS+=	gmake

.include "../../security/openssl/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
