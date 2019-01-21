# $NetBSD: Makefile,v 1.1 2019/01/21 16:57:41 youri Exp $
#

VERSION=	11.0.0
PKGNAME=	unicode-ucd-${VERSION}
DISTNAME=	UCD
CATEGORIES=	fonts
MASTER_SITES+=	http://www.unicode.org/Public/zipped/${VERSION}/
DISTFILES=	UCD.zip Unihan.zip

EXTRACT_ONLY=	UCD.zip

MAINTAINER=	youri@NetBSD.org
HOMEPAGE=	https://www.unicode.org/
COMMENT=	Unicode Character Database
#LICENSE=	http://www.unicode.org/copyright.html

WRKSRC=		${WRKDIR}
DIST_SUBDIR=	${DISTNAME}
NO_CONFIGURE=	YES
NO_BUILD=	YES

INSTALLATION_DIR=	${DESTDIR}${PREFIX}/share/unicode/ucd/

do-install:
	${INSTALL_DATA_DIR} ${INSTALLATION_DIR}/auxiliary
	${INSTALL_DATA_DIR} ${INSTALLATION_DIR}/extracted
	${INSTALL_DATA} ${WRKSRC}/auxiliary/* ${INSTALLATION_DIR}/auxiliary
	${INSTALL_DATA} ${WRKSRC}/extracted/* ${INSTALLATION_DIR}/extracted
	${INSTALL_DATA} ${WRKSRC}/*.txt ${WRKSRC}/*.pdf ${INSTALLATION_DIR}
	# Required by gucharmap
	${INSTALL_DATA} ${DISTDIR}/${DIST_SUBDIR}/Unihan.zip ${INSTALLATION_DIR}

.include "../../mk/bsd.pkg.mk"
