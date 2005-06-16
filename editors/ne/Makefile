# $NetBSD: Makefile,v 1.9 2005/06/16 06:57:49 jlam Exp $

DISTNAME=	ne-1.31
CATEGORIES=	editors
MASTER_SITES=	ftp://ftp.cus.cam.ac.uk/pub/software/programs/NE/
DISTFILES=	${DISTNAME}.tar.gz ne.manpage.1 NE.spec.ascii NE.changes.spec

MAINTAINER=	bjh@mail.dotcom.fr
COMMENT=	Re-write of Phoenix E.  A sensible light-weight editor

DIST_SUBDIR=	${PKGNAME}
WRKSRC=		${WRKDIR}/src

EXTRACT_ONLY=	${DISTNAME}.tar.gz

BUILD_TARGET=	NetBSD ne

INSTALLATION_DIRS=	bin man/man1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/nenewp ${PREFIX}/bin/ne
	${INSTALL_MAN} ${_DISTDIR}/ne.manpage.1 ${PREFIX}/man/man1/ne.1
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/ne
	${INSTALL_DATA} ${_DISTDIR}/NE.spec.ascii ${_DISTDIR}/NE.changes.spec \
		${WRKSRC}/LICENCE ${PREFIX}/share/doc/ne

.include "../../mk/bsd.pkg.mk"
