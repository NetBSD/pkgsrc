# $NetBSD: Makefile,v 1.16 2012/10/06 11:54:44 asau Exp $

DISTNAME=		new_brain
PKGNAME=		knightcap-brain-19980616
CATEGORIES=		games
MASTER_SITES=		ftp://samba.anu.edu.au/pub/KnightCap/
EXTRACT_SUFX=		.dat

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://anu.samba.org/KnightCap/
COMMENT=		Book of losing moves for KnightCap

ONLY_FOR_PLATFORM=	*-*-i386

WRKSRC=			${WRKDIR}
DIST_SUBDIR=		${PKGNAME_NOREV}

EXTRACT_ONLY=		# empty
NO_CONFIGURE=		yes

EGDIR=			${PREFIX}/share/examples/knightcap
INSTALLATION_DIRS=	bin

do-build:
	${SED} -e "s,@PREFIX@,${PREFIX},g" < ${FILESDIR:Q}/newbrain.sh \
		> ${WRKSRC:Q}/newbrain.sh

do-install:
	${INSTALL_SCRIPT} ${WRKSRC:Q}/newbrain.sh \
		${DESTDIR}${PREFIX:Q}/bin/newbrain
	${INSTALL_DATA_DIR} ${DESTDIR}${EGDIR:Q}
	${INSTALL_DATA} ${DISTDIR:Q}/${DIST_SUBDIR:Q}/new_brain.dat \
		${DESTDIR}${EGDIR:Q}/brain.dat

.include "../../mk/bsd.pkg.mk"
