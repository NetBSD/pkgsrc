# $NetBSD: Makefile,v 1.10 2012/10/08 09:57:25 asau Exp $
#
# Update instructions:
# . bump PKGNAME to today's date
# . get distfiles from OMASTER_SITES
# . update ${DISTDIR}/${PKGNAME_NOREV} to
#   ftp.NetBSD.org:/pub/NetBSD/packages/distfiles/LOCAL_PORTS/

DISTNAME=	kanjidic2
PKGNAME=	kanjidic2-20061208
CATEGORIES=	japanese misc
MASTER_SITES=	${MASTER_SITE_LOCAL:=${PKGNAME_NOREV}/}
OMASTER_SITES=	ftp://ftp.cc.monash.edu.au/pub/nihongo/
EXTRACT_SUFX=	.gz
DISTFILES=	kanjidic2.xml.gz kanjidic_doc.html kanjidic2_ov.html kanjidic2_dtd.gz kanjidic2_xsd.gz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.csse.monash.edu.au/~jwb/kanjidic.html
COMMENT=	Japanese Kanji information

DIST_SUBDIR=	${PKGNAME_NOREV}
EXTRACT_ONLY=	kanjidic2.xml.gz kanjidic2_dtd.gz kanjidic2_xsd.gz
WRKSRC=		${WRKDIR}

NO_BUILD=	yes

do-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/kanjidic2
	${INSTALL_DATA} ${WRKSRC}/kanjidic2.xml \
		${DESTDIR}${PREFIX}/share/kanjidic2/
	${INSTALL_DATA} ${WRKSRC}/kanjidic2_dtd \
		${DESTDIR}${PREFIX}/share/kanjidic2/kanjidic2.dtd
	${INSTALL_DATA} ${WRKSRC}/kanjidic2_xsd \
		${DESTDIR}${PREFIX}/share/kanjidic2/kanjidic2.xsd
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/doc/kanjidic2
	${INSTALL_DATA} ${DISTDIR}/${DIST_SUBDIR}/kanjidic_doc.html \
		${DESTDIR}${PREFIX}/share/doc/kanjidic2
	${INSTALL_DATA} ${DISTDIR}/${DIST_SUBDIR}/kanjidic2_ov.html \
		${DESTDIR}${PREFIX}/share/doc/kanjidic2

.include "../../mk/bsd.pkg.mk"
