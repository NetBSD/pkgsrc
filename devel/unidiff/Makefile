# $NetBSD: Makefile,v 1.9 2005/05/09 15:18:03 xtraeme Exp $
#

DISTNAME=	part01
PKGNAME=	unidiff-1.0
PKGREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	http://www.landfield.com/software/comp.sources.misc/archive-name/volume25/unidiff/
EXTRACT_SUFX=	.gz

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	#
COMMENT=	Converts between uni-diffs and context diffs

BUILD_DEPENDS=	gsharutils>=4.2.1:../../archivers/gsharutils

WRKSRC=		${WRKDIR}
EXTRACT_CMD=	zcat ${DOWNLOADED_DISTFILE} | ${PREFIX}/bin/gunshar

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/unify ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/unipatch ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/unify.1 ${PREFIX}/man/man1

.include "../../mk/bsd.pkg.mk"
