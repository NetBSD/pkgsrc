# $NetBSD: Makefile,v 1.1.1.1 2000/10/15 08:39:18 jlam Exp $

DISTNAME=		knightcap-brain-19980616
CATEGORIES=		games
MASTER_SITES=		ftp://samba.anu.edu.au/pub/KnightCap/
DISTFILES=		new_brain.dat

MAINTAINER=		jlam@netbsd.org
HOMEPAGE=		http://anu.samba.org/KnightCap/

ONLY_FOR_PLATFORMS=	*-*-i386

DIST_SUBDIR=		${PKGNAME}

EXTRACT_ONLY=		# empty
NO_WRKSUBDIR=		# defined
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
