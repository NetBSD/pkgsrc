# $NetBSD: Makefile,v 1.1 2018/08/23 22:08:07 kamil Exp $

DISTNAME=	honggfuzz-1.7
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=google/}

MAINTAINER=	tomsun.0.7@gmail.com
HOMEPAGE=	https://github.com/google/honggfuzz/
COMMENT=	Security oriented fuzzer based on code coverage
LICENSE=	apache-2.0

USE_TOOLS+=	bash:run gmake

.include "../../lang/libBlocksRuntime/buildlink3.mk"
.include "../../devel/capstone/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
