# $NetBSD: Makefile,v 1.13 2001/05/02 04:02:05 fredb Exp $
#

DISTNAME=	Squeak2.7-src
PKGNAME=	squeak-2.7
CATEGORIES=	lang
MASTER_SITES=	ftp://ftp.inria.fr/INRIA/Projects/SOR/users/piumarta/squeak/
DISTFILES=	Squeak2.7-src.tar.gz Squeak2.7.image.gz Squeak2.7.changes.gz SqueakV2.sources.gz

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.squeak.org/
COMMENT=	Full Smalltalk 80 with portability to UN*X, Mac, and Windows

BUILD_DEPENDS+=	autoconf-2.13:../../devel/autoconf

DIST_SUBDIR=	squeak
EXTRACT_ONLY=	Squeak2.7-src.tar.gz
USE_X11=	yes
USE_GMAKE=	yes
NO_WRKSUBDIR=	yes

ALL_TARGET=	squeak

pre-configure:
	cd ${WRKSRC}/conf; ${LOCALBASE}/bin/autoconf

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/squeak
	${INSTALL_PROGRAM} ${WRKSRC}/`${WRKSRC}/conf/config.guess`/squeak ${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/ReadMe.txt ${PREFIX}/share/squeak
	for f in Squeak2.7.changes Squeak2.7.image SqueakV2.sources ; do	\
		${GZCAT} ${DISTDIR}/${DIST_SUBDIR}/$$f.gz > ${PREFIX}/share/squeak/$$f; \
	done

.include "../../mk/bsd.pkg.mk"
