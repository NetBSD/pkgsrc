# $NetBSD: Makefile,v 1.26 2026/11/22 16:07:37 drixter Exp $

DISTNAME=	mcsim-6.2.0
CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_GNU:=mcsim/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.gnu.org/software/mcsim
COMMENT=	Monte Carlo Simulation software
LICENSE=	gnu-gpl-v3

CONFLICTS+=		mono-[0-9]* # bin/mod

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	makeinfo
INFO_FILES=	yes

REPLACE_SH=	sim/makemcsim.in sim/makemcsimd.in sim/makemcsims.in sim/makemcsimp.in

TEST_TARGET=	check

.include "../../math/gsl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
