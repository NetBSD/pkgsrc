# $NetBSD: Makefile,v 1.31 2023/12/17 14:10:03 nros Exp $

DISTNAME=	Maude-2.6
PKGNAME=	maude-2.6
PKGREVISION=	1
CATEGORIES=	lang
MASTER_SITES=	http://maude.cs.uiuc.edu/download/
MASTER_SITES+=	http://maude.cs.uiuc.edu/download/current/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://maude.cs.uiuc.edu/
COMMENT=	System for equational and rewriting logic specification/programming
LICENSE=	gnu-gpl-v2

MAKE_JOBS_SAFE=		no

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--datadir=${PREFIX}/share/${PKGBASE}
USE_LANGUAGES=	c c++
USE_TOOLS+=	flex bison
TEST_TARGET=	check

# Fails with C++14 default language.
FORCE_CXX_STD=	c++03

post-install:
	cd ${WRKSRC}/src/Main && ${INSTALL_DATA} *.maude \
		${DESTDIR}${PREFIX}/share/${PKGBASE}

.include "../../devel/buddy/buildlink3.mk"
.include "../../devel/gmp/buildlink3.mk"
.include "../../devel/libsigsegv/buildlink3.mk"
.include "../../devel/libtecla/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
