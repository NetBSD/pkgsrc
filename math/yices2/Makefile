# $NetBSD: Makefile,v 1.4 2020/07/13 19:45:45 alnsn Exp $

PKGNAME=	yices2-2.6.1
DISTNAME=	Yices-${PKGVERSION}
GITHUB_TAG=	${DISTNAME}
CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_GITHUB:=SRI-CSL/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://yices.csl.sri.com/
COMMENT=	Yices 2 SMT solver
LICENSE=	gnu-gpl-v3

BUILD_DEPENDS+=	gperf-[0-9]*:../../devel/gperf

USE_TOOLS+=		autoconf bash gmake
USE_LANGUAGES=		c
GNU_CONFIGURE=		yes
USE_GNU_CONFIGURE_HOST=	no
TEST_TARGET=		check

REPLACE_BASH+=	tests/regress/check.sh

WRKSRC=		${WRKDIR}/yices2-${DISTNAME}

pre-configure:
	 cd ${WRKSRC} && autoconf

pre-install:
	cd ${WRKSRC} && make dist

.include "../../devel/gmp/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
