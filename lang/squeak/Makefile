# $NetBSD: Makefile,v 1.3 2000/02/12 20:49:49 dmcmahill Exp $
#

DISTNAME=	Squeak2.6-src
PKGNAME=	squeak-2.6
CATEGORIES=	lang
MASTER_SITES=	http://www-sor.inria.fr/~piumarta/squeak/unix/release/ \
		ftp://ftp.cs.uni-magdeburg.de/pub/Smalltalk/Smalltalk/Squeak/unix/ \
		ftp://ftp.cs.uni-magdeburg.de/pub/Smalltalk/Smalltalk/Squeak/unix/image/ \
		http://www.nectar.com/distfiles/squeak/
DISTFILES=	Squeak2.6-src.tar.gz Squeak2.6.image.gz Squeak2.6.changes.gz

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.squeak.org/

DIST_SUBDIR=	squeak
EXTRACT_ONLY=	Squeak2.6-src.tar.gz
USE_X11=	yes
USE_GMAKE=	yes
NO_WRKSUBDIR=	yes
ALL_TARGET=	squeak

do-config:
	cd ${WRKSRC}; ${GMAKE} config

do-install:
	${MKDIR} ${PREFIX}/share/squeak
	${INSTALL_PROGRAM} ${WRKSRC}/`${WRKSRC}/conf/config.guess`/squeak ${PREFIX}/bin
	for f in Squeak2.6.changes Squeak2.6.image; do			\
		${GZCAT} ${DISTDIR}/${DIST_SUBDIR}/$$f.gz > ${PREFIX}/share/squeak/$$f; \
	done

.include "../../mk/bsd.pkg.mk"
