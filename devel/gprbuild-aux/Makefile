# $NetBSD: Makefile,v 1.7 2016/11/25 20:36:49 marino Exp $
#

DISTNAME=	gprbuild-aux-${SNAPSHOT}
CATEGORIES=	devel
MASTER_SITES=	https://codeload.github.com/AdaCore/gprbuild/tar.gz/${TAGNAME}?dummy=/
DISTFILES=	gprbuild-${TAGNAME}.tar.gz

MAINTAINER=	draco@marino.st
HOMEPAGE=	http://www.adacore.com/home/products/gnatpro/toolsuite/gprbuild/
COMMENT=	Adacore multi-language software build tool
LICENSE=	gnu-gpl-v3

SNAPSHOT=		20160609
TAGNAME=		376670f
USE_LANGUAGES=		c ada
BUILD_MAKE_FLAGS=	BUILD=production \
			PROCESSORS=${MAKE_JOBS:U1:Q}
MAKE_ENV=		ADA_PROJECT_PATH=${PREFIX}/lib/gnat
WRKSRC=			${WRKDIR}/gprbuild-${TAGNAME}
BUILD_DIRS=		${WRKSRC}/construction

post-patch:
	${MKDIR} ${WRKDIR}/trash ${BUILD_DIRS}
	${CP} ${FILESDIR}/Makefile.BSD ${BUILD_DIRS}/Makefile
	${MV} ${WRKSRC}/share/gprconfig/*.orig ${WRKDIR}/trash

.include "../../textproc/xmlada/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
