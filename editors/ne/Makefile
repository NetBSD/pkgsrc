# $NetBSD: Makefile,v 1.15 2012/10/03 11:43:38 asau Exp $

DISTNAME=	ne-1.31
CATEGORIES=	editors
MASTER_SITES=	ftp://ftp.cus.cam.ac.uk/pub/software/programs/NE/
DISTFILES=	${DISTNAME}.tar.gz ne.manpage.1 NE.spec.ascii NE.changes.spec

MAINTAINER=	bjh@mail.dotcom.fr
COMMENT=	Re-write of Phoenix E.  A sensible light-weight editor

MAKE_JOBS_SAFE=		no

DIST_SUBDIR=	${PKGNAME_NOREV}
WRKSRC=		${WRKDIR}/src

EXTRACT_ONLY=	${DISTNAME}.tar.gz

BUILD_TARGET=	NetBSD ne

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/nenewp ${DESTDIR}${PREFIX}/bin/ne
	${INSTALL_MAN} ${_DISTDIR}/ne.manpage.1 \
		${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/ne.1
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/doc/ne
	${INSTALL_DATA} ${_DISTDIR}/NE.spec.ascii ${_DISTDIR}/NE.changes.spec \
		${WRKSRC}/LICENCE ${DESTDIR}${PREFIX}/share/doc/ne

.include "../../mk/termcap.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
