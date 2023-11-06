# $NetBSD: Makefile,v 1.26 2023/11/06 14:00:23 wiz Exp $

DISTNAME=		ltm-1.2.1
CATEGORIES=		math
MASTER_SITES=		${MASTER_SITE_GITHUB:=libtom/}
GITHUB_PROJECT=		libtommath
GITHUB_RELEASE=		v${PKGVERSION_NOREV}
EXTRACT_SUFX=		.tar.xz

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://www.libtom.net/LibTomMath/
COMMENT=		Number theoretic multiple-precision integer library
LICENSE=		unlicense

WRKSRC=			${WRKDIR}/libtommath-${PKGVERSION_NOREV}
USE_LIBTOOL=		yes
MAKE_FILE=		makefile.shared
BUILD_TARGET=		default
USE_TOOLS+=		gmake

PKGCONFIG_OVERRIDE+=	libtommath.pc.in

INSTALLATION_DIRS=	share/doc/ltm

do-test:
	(cd ${WRKSRC};  \
	 gmake -f makefile mtest/mtest test; \
	 ./mtest/mtest | ./test)

post-install:
	${INSTALL_DATA} ${WRKSRC}/doc/bn.pdf ${DESTDIR}${PREFIX}/share/doc/ltm

.include "../../mk/bsd.pkg.mk"
