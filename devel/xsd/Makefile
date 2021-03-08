# $NetBSD: Makefile,v 1.40 2021/03/08 14:33:44 nia Exp $

DISTNAME=		xsd-4.0.0+dep
PKGNAME=		${DISTNAME:S/+dep//1}
CATEGORIES=		devel textproc
MASTER_SITES=		https://www.codesynthesis.com/download/xsd/${PKGVERSION_NOREV:R}/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://www.codesynthesis.com/products/xsd/
COMMENT=		W3C XML Schema to C++ data binding compiler
LICENSE=		gnu-gpl-v2

USE_TOOLS+=		bash gmake gm4
USE_LANGUAGES=		c c++11

GCC_REQD+=		4.7 # C++11

MAKE_FILE=		makefile

BUILD_TARGET=		# no default target should be passed to gmake.

MAKE_FLAGS+=		verbose=1
MAKE_FLAGS+=		install_prefix=${DESTDIR}${PREFIX}
MAKE_FLAGS+=		install_man_dir=${DESTDIR}${PREFIX}/${PKGMANDIR}

post-patch:
	# Avoid conflict with C++20 <version>
	${RM} -f ${WRKSRC}/version
	${RM} -f ${WRKSRC}/build/import/lib*/version

.include "../../devel/boost-libs/buildlink3.mk"
.include "../../textproc/xerces-c/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
