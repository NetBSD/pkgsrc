# $NetBSD: Makefile,v 1.4 2004/12/03 15:14:59 wiz Exp $
#

DISTNAME=		ljpg
PKGNAME=		ljpg-1.0
CATEGORIES=		graphics
MASTER_SITES=		ftp://ftp.cs.cornell.edu/pub/multimed/
EXTRACT_SUFX=		.tar.Z

MAINTAINER=		wiz@NetBSD.org
HOMEPAGE=		ftp://ftp.cs.cornell.edu/pub/multimed/
COMMENT=		Lossless JPEG codec

WRKSRC=			${WRKDIR}
DIST_SUBDIR=		${PKGNAME_NOREV}

USE_BUILDLINK3=		yes
BUILD_TARGET=		default

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/ljpeg
	${INSTALL_DATA} ${WRKSRC}/Copyright ${PREFIX}/share/doc/ljpeg
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/ljpeg
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/ljpeg
	${INSTALL_DATA} ${WRKSRC}/F-18* ${PREFIX}/share/examples/ljpeg

.include "../../mk/bsd.pkg.mk"
