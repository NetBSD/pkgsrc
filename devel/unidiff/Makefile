# $NetBSD: Makefile,v 1.1.1.1 2001/10/18 10:23:36 agc Exp $
#

DISTNAME=	part01
PKGNAME=	unidiff-1.0
CATEGORIES=	devel
MASTER_SITES=	http://www.landfield.com/software/comp.sources.misc/archive-name/volume25/unidiff/
EXTRACT_SUFX=	.gz

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	#
COMMENT=	converts between uni-diffs and context diffs

BUILD_DEPENDS=	gsharutils-4.2.1:../../archivers/gsharutils

EXTRACT_CMD=	zcat ${DOWNLOADED_DISTFILE} | gunshar
WRKSRC=		${WRKDIR}

do-install:
	${BSD_INSTALL_PROGRAM} ${WRKSRC}/unify ${PREFIX}/bin
	${BSD_INSTALL_PROGRAM} ${WRKSRC}/unipatch ${PREFIX}/bin
	${BSD_INSTALL_MAN} ${WRKSRC}/unify.1 ${PREFIX}/man/man1

.include "../../mk/bsd.pkg.mk"
