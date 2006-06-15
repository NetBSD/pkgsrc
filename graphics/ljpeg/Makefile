# $NetBSD: Makefile,v 1.6 2006/06/15 13:31:29 wiz Exp $
#

DISTNAME=		ljpg
PKGNAME=		ljpg-1.0
CATEGORIES=		graphics
MASTER_SITES=		ftp://ftp.cs.cornell.edu/pub/multimed/
EXTRACT_SUFX=		.tar.Z

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		ftp://ftp.cs.cornell.edu/pub/multimed/
COMMENT=		Lossless JPEG codec

WRKSRC=			${WRKDIR}
DIST_SUBDIR=		${PKGNAME_NOREV}

BUILD_TARGET=		default

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/ljpeg
	${INSTALL_DATA} ${WRKSRC}/Copyright ${PREFIX}/share/doc/ljpeg
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/ljpeg
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/ljpeg
	${INSTALL_DATA} ${WRKSRC}/F-18* ${PREFIX}/share/examples/ljpeg

.include "../../mk/bsd.pkg.mk"
