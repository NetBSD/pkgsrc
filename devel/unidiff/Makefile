# $NetBSD: Makefile,v 1.10 2005/06/16 06:57:48 jlam Exp $
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

INSTALLATION_DIRS=	bin man/man1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/unify ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/unipatch ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/unify.1 ${PREFIX}/man/man1

.include "../../mk/bsd.pkg.mk"
