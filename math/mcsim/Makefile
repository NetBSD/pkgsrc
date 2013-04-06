# $NetBSD: Makefile,v 1.23 2013/04/06 20:27:24 rodent Exp $

DISTNAME=	mcsim-5.4.0
PKGREVISION=	1
CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_GNU:=mcsim/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.gnu.org/software/mcsim
COMMENT=	Monte Carlo Simulation software

CONFLICTS+=		mono-[0-9]* # bin/mod

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	makeinfo
INFO_FILES=	yes

REPLACE_SH=	sim/makemcsim.in sim/makemcsimd.in sim/makemcsims.in

TEST_TARGET=	check

.include "../../math/gsl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
