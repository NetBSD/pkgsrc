# $NetBSD: Makefile,v 1.6 2006/12/08 16:59:56 wiz Exp $
#
# Update instructions:
# . bump PKGNAME to today's date
# . get distfiles from OMASTER_SITES
# . update ${DISTDIR}/${PKGNAME_NOREV} to
#   ftp.NetBSD.org:/pub/NetBSD/packages/distfiles/LOCAL_PORTS/

DISTNAME=	JMdict
PKGNAME=	JMdict-20061208
CATEGORIES=	japanese misc
MASTER_SITES=	${MASTER_SITE_LOCAL:=${PKGNAME_NOREV}/}
OMASTER_SITES=	ftp://ftp.cc.monash.edu.au/pub/nihongo/
EXTRACT_SUFX=	.gz
DISTFILES=	jmdict_proj_desc.html JMdict.gz JMdict.dtd

MAINTAINER=	wiz@NetBSD.org
HOMEPAGE=	http://www.csse.monash.edu.au/~jwb/edict.html
COMMENT=	Japanese-Multilingual electronic dictionary

WRKSRC=		${WRKDIR}
DIST_SUBDIR=	${PKGNAME_NOREV}
EXTRACT_ONLY=	JMdict.gz

NO_BUILD=	yes

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/JMdict
	${INSTALL_DATA} ${WRKSRC}/JMdict ${PREFIX}/share/JMdict
	${INSTALL_DATA} ${DISTDIR}/${DIST_SUBDIR}/JMdict.dtd \
		${PREFIX}/share/JMdict
	${INSTALL_DATA} ${DISTDIR}/${DIST_SUBDIR}/JMdict.gz \
		${PREFIX}/share/JMdict
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/JMdict
	${INSTALL_DATA} ${DISTDIR}/${DIST_SUBDIR}/jmdict_proj_desc.html \
		${PREFIX}/share/doc/JMdict

.include "../../mk/bsd.pkg.mk"
