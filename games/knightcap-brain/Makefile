# $NetBSD: Makefile,v 1.18 2015/01/04 06:11:03 dholland Exp $

DISTNAME=		new_brain
PKGNAME=		knightcap-brain-19980616
CATEGORIES=		games
MASTER_SITES=		ftp://ftp.samba.org/pub/KnightCap/
EXTRACT_SUFX=		.dat

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://samba.org/KnightCap/
COMMENT=		Book of losing moves for KnightCap

WRKSRC=			${WRKDIR}
DIST_SUBDIR=		${PKGNAME_NOREV}

EXTRACT_ONLY=		# empty
NO_CONFIGURE=		yes

# The prefab brain file is not especially portable (see the top of
# brain.c in knightcap; the file is a binary array of brain_entry) and
# while most of it is adequate but not ideal and should be portable
# among platforms of the same endianness (even ILP32 vs. LP64 ones),
# it unfortunately contains two fields of type time_t. We think the
# posted brain file is from 32-bit x86, probably Linux, so it will
# work on little-endian machines where time_t is still 32 bit. This
# excludes at least NetBSD 6.0 and up, and at least some of the 64-bit
# Linux ports, but I don't know for sure which ones. So begin by
# allowing little-endian platforms and then excluding ones known not
# to work. Add more as needed; a brain file with mismatched time_t
# won't load. Note that while the existing brain file could easily be
# translated, if anyone feels like doing that they should probably
# translate the posted one to a portable format (e.g. compressed JSON
# or something, or just plain text) and provide a loader for that
# format upstream.

.include "../../mk/bsd.prefs.mk"
ONLY_FOR_PLATFORM=	${LITTLEENDIANPLATFORMS}
NOT_FOR_PLATFORM=	NetBSD-[6-9].*-* NetBSD-1[1-9].*-*
NOT_FOR_PLATFORM+=	Linux-*-alpha

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
