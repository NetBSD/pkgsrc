# $NetBSD: Makefile,v 1.14 2001/05/16 02:27:52 fredb Exp $
#

DISTNAME=	Squeak-3.0pre2
PKGNAME=	squeak-3.0pre2
CATEGORIES=	lang
MASTER_SITES=	ftp://st.cs.uiuc.edu/Smalltalk/Squeak/3.0/platform-independent/
MASTER_SITES+=	ftp://ftp.inria.fr/INRIA/Projects/SOR/users/piumarta/squeak/
DISTFILES=	ReadMe.txt.gz Squeak3.0-3545.zip SqueakV3.sources.gz
DISTFILES+=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	fredb@netbsd.org
HOMEPAGE=	http://www.squeak.org/
COMMENT=	Full Smalltalk 80 with portability to UN*X, Mac, and Windows

BUILD_DEPENDS+=	autoconf-2.13:../../devel/autoconf
BUILD_DEPENDS+=	automake-1.4:../../devel/automake
BUILD_DEPENDS+=	unzip-*:../../archivers/unzip

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_X11=	yes

CPPFLAGS+=	-DNETBSD_OSS_HACK
CONFIGURE_ENV+=	CPPFLAGS="${CPPFLAGS}"
DIST_SUBDIR=	squeak
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}
WRKSRC=		${WRKDIR}/Squeak-3.0/build

CONFIGURE_SCRIPT= ${WRKSRC}/../src/unix/configure
LTCONFIG_OVERRIDE= ${WRKSRC}/../src/unix/ltconfig

post-extract:
.for f in ReadMe.txt.gz SqueakV3.sources.gz
	${GZCAT} ${DISTDIR}/${DIST_SUBDIR}/${f} > ${WRKDIR}/${f:C/.gz//}
.endfor
	cd ${WRKDIR} && \
	    ${LOCALBASE}/bin/unzip ${DISTDIR}/${DIST_SUBDIR}/Squeak3.0-3545.zip
	${MKDIR} ${WRKSRC}

pre-configure:
	cd ${WRKSRC}/../src/unix; \
	    ${LOCALBASE}/bin/aclocal && ${LOCALBASE}/bin/autoconf

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/squeak/3.0
.for f in ReadMe.txt SqueakV3.sources
	${INSTALL_DATA} ${WRKDIR}/${f} ${PREFIX}/share/squeak/
.endfor
.for f in Squeak3.0final.changes Squeak3.0final.image
	${INSTALL_DATA} ${WRKDIR}/${f} \
		${PREFIX}/share/squeak/3.0/${f:C/final//}
.endfor

.include "../../mk/bsd.pkg.mk"
