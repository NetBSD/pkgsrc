# $NetBSD: Makefile,v 1.1 1998/08/14 22:14:40 tron Exp $

DISTNAME=	ne
PKGNAME=	ne-1.25
WRKSRC=		${WRKDIR}/src
CATEGORIES=	editors
MASTER_SITES=	ftp://ftp.cus.cam.ac.uk/pub/software/programs/NE/
DISTFILES=	ne.tar.gz ne.manpage.1 NE.spec.ascii NE.changes.spec
DIST_SUBDIR=	ne

MAINTAINER=	bjh@mail.dotcom.fr

EXTRACT_ONLY=	ne.tar.gz

post-extract:
	@${CP} ${_DISTDIR}/ne.manpage.1 ${_DISTDIR}/NE.spec.ascii \
		${_DISTDIR}/NE.changes.spec ${WRKSRC}

ALL_TARGET=	NetBSD ne

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/nenew ${PREFIX}/bin/ne
	${INSTALL_MAN} ${WRKSRC}/ne.manpage.1 ${PREFIX}/man/man1/ne.1
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/ne
	${INSTALL_DATA} ${WRKSRC}/NE.spec.ascii ${WRKSRC}/NE.changes.spec \
		${WRKSRC}/LICENCE ${PREFIX}/share/doc/ne

.include "../../mk/bsd.pkg.mk"
