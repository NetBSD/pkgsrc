# $NetBSD: Makefile,v 1.11 2012/10/08 09:57:25 asau Exp $
#
# Update instructions:
# . bump PKGNAME to today's date
# . get distfiles from OMASTER_SITES
# . update ${DISTDIR}/${PKGNAME_NOREV} to
#   ftp.NetBSD.org:/pub/NetBSD/packages/distfiles/LOCAL_PORTS/

DISTNAME=	kanjidic
PKGNAME=	kanjidic-20061208
CATEGORIES=	japanese misc
MASTER_SITES=	${MASTER_SITE_LOCAL:=${PKGNAME_NOREV}/}
OMASTER_SITES=	ftp://ftp.cc.monash.edu.au/pub/nihongo/
EXTRACT_SUFX=	.gz
DISTFILES=	kanjidic.gz kanjidic.doc

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.csse.monash.edu.au/~jwb/kanjidic.html
COMMENT=	Japanese Kanji information

WRKSRC=		${WRKDIR}
DIST_SUBDIR=	${PKGNAME_NOREV}
EXTRACT_ONLY=	kanjidic.gz

NO_BUILD=	yes

do-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/kanjidic
	${INSTALL_DATA} ${WRKSRC}/kanjidic ${DESTDIR}${PREFIX}/share/kanjidic
	${INSTALL_DATA} ${DISTDIR}/${DIST_SUBDIR}/kanjidic.gz \
		${DESTDIR}${PREFIX}/share/kanjidic
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/doc/kanjidic
	${INSTALL_DATA} ${DISTDIR}/${DIST_SUBDIR}/kanjidic.doc \
		${DESTDIR}${PREFIX}/share/doc/kanjidic

.include "../../mk/bsd.pkg.mk"
