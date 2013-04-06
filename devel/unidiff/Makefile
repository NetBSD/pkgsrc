# $NetBSD: Makefile,v 1.18 2013/04/06 12:04:00 rodent Exp $
#

DISTNAME=	part01
PKGNAME=	unidiff-1.0
PKGREVISION=	2
CATEGORIES=	devel
MASTER_SITES=	http://www.landfield.com/software/comp.sources.misc/archive-name/volume25/unidiff/
EXTRACT_SUFX=	.gz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	#
COMMENT=	Converts between uni-diffs and context diffs

BUILD_DEPENDS+=	gsharutils>=4.2.1:../../archivers/gsharutils

WRKSRC=		${WRKDIR}
EXTRACT_CMD=	${GZCAT} $$extract_file | ${PREFIX}/bin/gunshar

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/unify ${DESTDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/unipatch ${DESTDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/unify.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1

.include "../../mk/bsd.pkg.mk"
