# $NetBSD: Makefile,v 1.14 2024/05/06 08:40:28 jperkin Exp $
#

ORDCALCVER=	0.2
PKGNAME=	ordCalc-${ORDCALCVER}
DISTNAME=	ordCalc_${ORDCALCVER}
PKGREVISION=	8
CATEGORIES=	math
MASTER_SITES=	http://mtnmath.com/ord/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	is@NetBSD.org
HOMEPAGE=	https://mtnmath.com/ord/
COMMENT=	Ordinal arithmetic calculator and research tool
LICENSE=	gnu-gpl-v2

USE_LANGUAGES=	c++
USE_TOOLS+=	bash bison flex gmake
USE_LIBTOOL=	yes

BUILD_TARGET=	EXE
TEST_TARGET=	TEST

DOCS=		${DESTDIR}${PREFIX}/share/doc/ordCalc

AUTO_MKDIRS=	yes

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/ord ${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/README ${DOCS}
	${INSTALL_DATA} ${WRKSRC}/ordCalc.pdf ${DOCS}
	${INSTALL_DATA} ${WRKSRC}/ordinal.pdf ${DOCS}



.include "../../devel/gmp/buildlink3.mk"
.include "../../devel/ncurses/buildlink3.mk"
.include "../../mk/readline.buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
