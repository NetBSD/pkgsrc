# $NetBSD: Makefile,v 1.7 2003/07/21 16:43:48 martti Exp $
#

DISTNAME=	part01
PKGNAME=	unidiff-1.0
WRKSRC=		${WRKDIR}
CATEGORIES=	devel
MASTER_SITES=	http://www.landfield.com/software/comp.sources.misc/archive-name/volume25/unidiff/
EXTRACT_SUFX=	.gz

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	#
COMMENT=	Converts between uni-diffs and context diffs

BUILD_DEPENDS=	gsharutils-4.2.1:../../archivers/gsharutils

EXTRACT_CMD=	zcat ${DOWNLOADED_DISTFILE} | ${PREFIX}/bin/gunshar

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/unify ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/unipatch ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/unify.1 ${PREFIX}/man/man1

.include "../../mk/bsd.pkg.mk"
