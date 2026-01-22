# $NetBSD: Makefile,v 1.22 2026/01/22 08:45:49 wiz Exp $

DISTNAME=	ppl-1.2
PKGREVISION=	4
CATEGORIES=	math
MASTER_SITES=	#

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.bugseng.com/ppl/
COMMENT=	The Parma Polyhedra Library
LICENSE=	gnu-gpl-v3

USE_LIBTOOL=	yes
USE_TOOLS+=	autoconf automake gmake perl
DEPENDS+=	gsed-[0-9]*:../../textproc/gsed

USE_LANGUAGES=	c c++
GNU_CONFIGURE=	yes

# Fails with C++14 default language
FORCE_CXX_STD=		gnu++03

MAKE_ENV+=		lt_cv_path_SED=${PREFIX}/bin/gsed
#CONFIGURE_ARGS+=	--enable-interfaces=c,cxx

do-build:
	set -e; cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${GMAKE}

TEST_TARGET=	check

.include "../../devel/gmp/buildlink3.mk"
.include "../../math/mpfr/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
