# $NetBSD: Makefile,v 1.9 2007/07/08 09:43:49 wiz Exp $
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
	${INSTALL_DATA_DIR} ${PREFIX}/share/kanjidic
	${INSTALL_DATA} ${WRKSRC}/kanjidic ${PREFIX}/share/kanjidic
	${INSTALL_DATA} ${DISTDIR}/${DIST_SUBDIR}/kanjidic.gz \
		${PREFIX}/share/kanjidic
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/kanjidic
	${INSTALL_DATA} ${DISTDIR}/${DIST_SUBDIR}/kanjidic.doc \
		${PREFIX}/share/doc/kanjidic

.include "../../mk/bsd.pkg.mk"
