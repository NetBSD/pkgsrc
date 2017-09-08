# $NetBSD: Makefile,v 1.5 2017/09/08 09:51:24 jaapb Exp $

DISTNAME=	z3-4.4.1
GITHUB_TAG=	${DISTNAME}
PKGREVISION=	4
CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_GITHUB:=Z3Prover/}
PATCHFILES+=	z3-jumbo-patch-20151123.gz
SITES.z3-jumbo-patch-20151123.gz=\
			http://www.NetBSD.org/~dholland/patchkits/z3/
PATCH_DIST_STRIP=	-p1

MAINTAINER=	dholland@NetBSD.org
HOMEPAGE=	https://github.com/Z3Prover/z3/
COMMENT=	The Z3 theorem prover / SMT solver
LICENSE=	mit

WRKSRC=		${WRKDIR}/z3-${DISTNAME}
HAS_CONFIGURE=	yes
USE_LANGUAGES=	c c++
BUILD_DIRS=	build
PY_PATCHPLIST=	yes

CONFIGURE_ENV+=		PYTHON=${PYTHONBIN}
CONFIGURE_ARGS+=	--destdir=${DESTDIR} --prefix=${PREFIX}

.include "options.mk"

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
