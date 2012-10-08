# $NetBSD: Makefile,v 1.10 2012/10/08 09:57:20 asau Exp $
#
# Update instructions:
# . bump PKGNAME to today's date
# . get distfiles from OMASTER_SITES
# . update ${DISTDIR}/${PKGNAME_NOREV} to
#   ftp.NetBSD.org:/pub/NetBSD/packages/distfiles/LOCAL_PORTS/

DISTNAME=	edict
PKGNAME=	edict-20061208
CATEGORIES=	japanese misc
MASTER_SITES=	${MASTER_SITE_LOCAL:=${PKGNAME_NOREV}/}
OMASTER_SITES=	ftp://ftp.cc.monash.edu.au/pub/nihongo/
EXTRACT_SUFX=	.gz
DISTFILES=	edict.gz edict_doc.html

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.csse.monash.edu.au/~jwb/edict.html
COMMENT=	Japanese-English dictionary file

WRKSRC=		${WRKDIR}
DIST_SUBDIR=	${PKGNAME_NOREV}
EXTRACT_ONLY=	edict.gz

NO_BUILD=	yes

do-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/edict
	${INSTALL_DATA} ${WRKSRC}/edict ${DESTDIR}${PREFIX}/share/edict/
	${INSTALL_DATA} ${DISTDIR}/${DIST_SUBDIR}/edict.gz \
		${DESTDIR}${PREFIX}/share/edict
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/doc/edict
	${INSTALL_DATA} ${DISTDIR}/${DIST_SUBDIR}/edict_doc.html \
		${DESTDIR}${PREFIX}/share/doc/edict

.include "../../mk/bsd.pkg.mk"
