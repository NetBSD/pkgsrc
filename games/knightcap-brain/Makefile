# $NetBSD: Makefile,v 1.7 2003/07/21 16:49:52 martti Exp $

DISTNAME=		new_brain
PKGNAME=		knightcap-brain-19980616
WRKSRC=			${WRKDIR}
CATEGORIES=		games
MASTER_SITES=		ftp://samba.anu.edu.au/pub/KnightCap/
EXTRACT_SUFX=		.dat

MAINTAINER=		jlam@NetBSD.org
HOMEPAGE=		http://anu.samba.org/KnightCap/
COMMENT=		Book of losing moves for KnightCap

ONLY_FOR_PLATFORMS=	*-*-i386

DIST_SUBDIR=		${PKGNAME}

EXTRACT_ONLY=		# empty
NO_CONFIGURE=		# defined

EGDIR=			${PREFIX}/share/examples/knightcap

do-build:
	${SED} -e "s,@PREFIX@,${PREFIX},g" < ${FILESDIR}/newbrain.sh \
		> ${WRKSRC}/newbrain.sh

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/newbrain.sh ${PREFIX}/bin/newbrain
	${INSTALL_DATA_DIR} ${EGDIR}
	${INSTALL_DATA} ${DISTDIR}/${DIST_SUBDIR}/new_brain.dat \
		${EGDIR}/brain.dat

.include "../../mk/bsd.pkg.mk"
