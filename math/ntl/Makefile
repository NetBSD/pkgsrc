# $NetBSD: Makefile,v 1.40 2022/06/28 11:34:37 wiz Exp $

DISTNAME=		ntl-11.5.1
PKGREVISION=		1
CATEGORIES=		math devel
MASTER_SITES=		https://www.shoup.net/ntl/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://www.shoup.net/ntl/
COMMENT=		C++ library for doing number theory
LICENSE=		gnu-lgpl-v2.1

WRKSRC=			${WRKDIR}/${DISTNAME}/src
HAS_CONFIGURE=		yes
CONFIGURE_ARGS+=	DEF_PREFIX=${PREFIX}
USE_LANGUAGES=		c c++
USE_TOOLS+=		perl
MAKE_FILE=		makefile
TEST_TARGET=		check

.include "../../devel/gmp/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
