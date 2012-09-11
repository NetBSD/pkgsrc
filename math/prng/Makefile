# $NetBSD: Makefile,v 1.2 2012/09/11 23:04:30 asau Exp $

DISTNAME=	prng-3.0.2
CATEGORIES=	math
MASTER_SITES=	http://statistik.wu-wien.ac.at/software/prng/

MAINTAINER=	wenheping@gmail.com
HOMEPAGE=	http://statistik.wu-wien.ac.at/software/prng/
COMMENT=	Portable, high-performance ANSI-C pseudorandom number generators

LICENSE=	gnu-gpl-v2

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_TOOLS+=		makeinfo
GNU_CONFIGURE=		yes
INFO_FILES=		yes
TEST_TARGET=		check

.include "../../mk/bsd.pkg.mk"
