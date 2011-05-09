# $NetBSD: Makefile,v 1.20 2011/05/09 20:59:10 asau Exp $

DISTNAME=	mcsim-5.4.0
CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_GNU:=mcsim/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.gnu.org/software/mcsim
COMMENT=	Monte Carlo Simulation software

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	makeinfo
INFO_FILES=	# PLIST

REPLACE_SH=	sim/makemcsim.in sim/makemcsimd.in sim/makemcsims.in

TEST_TARGET=	check

.include "../../math/gsl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
