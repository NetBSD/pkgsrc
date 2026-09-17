# $NetBSD: Makefile,v 1.8 2026/09/17 13:45:03 wiz Exp $

DISTNAME=	yices2-2.7.0
CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_GITHUB:=SRI-CSL/}
GITHUB_TAG=	yices-${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://yices.csl.sri.com/
COMMENT=	Yices 2 SMT solver
LICENSE=	gnu-gpl-v3

TOOL_DEPENDS+=	gperf-[0-9]*:../../devel/gperf

USE_TOOLS+=		autoconf bash gmake
USE_LANGUAGES=		c
GNU_CONFIGURE=		yes
USE_GNU_CONFIGURE_HOST=	no
BUILD_TARGET=		obj lib bin
TEST_TARGET=		check

REPLACE_BASH+=	tests/regress/check.sh

WRKSRC=		${WRKDIR}/yices2-yices-${PKGVERSION_NOREV}

pre-configure:
	 cd ${WRKSRC} && autoconf

pre-install:
	cd ${WRKSRC} && make dist

.include "../../devel/gmp/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
