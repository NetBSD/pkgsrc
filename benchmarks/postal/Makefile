# $NetBSD: Makefile,v 1.16 2011/11/24 01:15:41 marino Exp $

DISTNAME=	postal-0.70
CATEGORIES=	benchmarks
MASTER_SITES=	http://www.coker.com.au/postal/
EXTRACT_SUFX=	.tgz

MAINTAINER=	david@silicium.ath.cx
HOMEPAGE=	http://www.coker.com.au/postal/
COMMENT=	Tool for benchmarking SMTP/POP servers
LICENSE=	gnu-gpl-v3

PKG_INSTALLATION_TYPES=	overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes
USE_LANGUAGES=	c c++
USE_TOOLS+=	gmake

.include "../../security/openssl/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
