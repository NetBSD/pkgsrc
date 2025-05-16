# $NetBSD: Makefile,v 1.27 2025/05/16 20:15:39 zafer Exp $

DISTNAME=	postal-0.70
PKGREVISION=	6
CATEGORIES=	benchmarks
MASTER_SITES=	https://www.coker.com.au/postal/
EXTRACT_SUFX=	.tgz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.coker.com.au/postal/
COMMENT=	Tool for benchmarking SMTP/POP servers
LICENSE=	gnu-gpl-v3

GNU_CONFIGURE=	yes
USE_LANGUAGES=	c c++03
USE_TOOLS+=	gmake

.include "../../security/openssl/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
