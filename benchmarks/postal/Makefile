# $NetBSD: Makefile,v 1.23 2018/01/26 13:40:17 jperkin Exp $

DISTNAME=	postal-0.70
PKGREVISION=	4
CATEGORIES=	benchmarks
MASTER_SITES=	http://www.coker.com.au/postal/
EXTRACT_SUFX=	.tgz

MAINTAINER=	david@silicium.ath.cx
HOMEPAGE=	http://www.coker.com.au/postal/
COMMENT=	Tool for benchmarking SMTP/POP servers
LICENSE=	gnu-gpl-v3

GNU_CONFIGURE=	yes
USE_LANGUAGES=	c c++03
USE_TOOLS+=	gmake

.include "../../security/openssl/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
