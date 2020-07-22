# $NetBSD: Makefile,v 1.3 2020/07/22 21:53:59 kamil Exp $

DISTNAME=	honggfuzz-2.3.1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=google/}

MAINTAINER=	kamil@NetBSD.org
HOMEPAGE=	https://github.com/google/honggfuzz/
COMMENT=	Security oriented fuzzer based on code coverage
LICENSE=	apache-2.0

FORTIFY_SUPPORTED=	no # fortify-source intercepts some functions

USE_TOOLS+=	bash:run gmake

.include "../../lang/libBlocksRuntime/buildlink3.mk"
.include "../../devel/capstone/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
