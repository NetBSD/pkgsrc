# $NetBSD: Makefile,v 1.8 2001/02/05 09:00:59 tron Exp $
#

DISTNAME=	Squeak2.7-src
PKGNAME=	squeak-2.7
CATEGORIES=	lang
MASTER_SITES=	ftp://ftp.inria.fr/INRIA/Projects/SOR/users/piumarta/squeak/
DISTFILES=	Squeak2.7-src.tar.gz Squeak2.7.image.gz Squeak2.7.changes.gz SqueakV2.sources.gz

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.squeak.org/

BUILD_DEPENDS+=	${LOCALBASE}/bin/${LOCALBASE}/bin/autoconf:../../devel/autoconf

DIST_SUBDIR=	squeak
EXTRACT_ONLY=	Squeak2.7-src.tar.gz
USE_X11=	yes
USE_GMAKE=	yes
NO_WRKSUBDIR=	yes

ALL_TARGET=	squeak
MAKE_ENV+=	LIBS="-Wl,-R${X11BASE}/lib -L${X11BASE}/lib"

pre-configure:
	cd ${WRKSRC}/conf; ${LOCALBASE}/bin/autoconf

do-install:
	${MKDIR} ${PREFIX}/share/squeak
	${INSTALL_PROGRAM} ${WRKSRC}/`${WRKSRC}/conf/config.guess`/squeak ${PREFIX}/bin
	for f in Squeak2.7.changes Squeak2.7.image SqueakV2.sources ; do		\
		${GZCAT} ${DISTDIR}/${DIST_SUBDIR}/$$f.gz > ${PREFIX}/share/squeak/$$f; \
	done

.include "../../mk/bsd.pkg.mk"
