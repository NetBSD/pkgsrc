# $NetBSD: Makefile,v 1.20 2001/11/29 19:46:12 jlam Exp $
#

DISTNAME=	Squeak-3.0
PKGNAME=	squeak-3.0
CATEGORIES=	lang
MASTER_SITES=	ftp://st.cs.uiuc.edu/Smalltalk/Squeak/3.0/platform-independent/
MASTER_SITES+=	ftp://st.cs.uiuc.edu/Smalltalk/Squeak/3.0/unix-linux/src/
MASTER_SITES+=	ftp://ftp.inria.fr/INRIA/Projects/SOR/users/piumarta/squeak/
DISTFILES=	ReadMe.txt.gz Squeak3.0-3552.zip SqueakV3.sources.gz
DISTFILES+=	${DISTNAME}-src${EXTRACT_SUFX}

MAINTAINER=	fredb@netbsd.org
HOMEPAGE=	http://www.squeak.org/
COMMENT=	Full Smalltalk 80 with portability to UN*X, Mac, and Windows

BUILD_DEPENDS+=	automake>=1.4:../../devel/automake
BUILD_DEPENDS+=	unzip-[0-9]*:../../archivers/unzip

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_X11=	yes

CPPFLAGS+=	-DNETBSD_OSS_HACK
DIST_SUBDIR=	squeak
EXTRACT_ONLY=	${DISTNAME}-src${EXTRACT_SUFX}
WRKSRC=		${WRKDIR}/Squeak-3.0/build

CONFIGURE_SCRIPT= ${WRKSRC}/../src/unix/configure
LTCONFIG_OVERRIDE= ${WRKSRC}/../src/unix/ltconfig

post-extract:
.for f in ReadMe.txt.gz SqueakV3.sources.gz
	${GZCAT} ${DISTDIR}/${DIST_SUBDIR}/${f} > ${WRKDIR}/${f:C/.gz//}
.endfor
	cd ${WRKDIR} && \
	    ${LOCALBASE}/bin/unzip ${DISTDIR}/${DIST_SUBDIR}/Squeak3.0-3552.zip
	${MKDIR} ${WRKSRC}

pre-configure:
	cd ${WRKSRC}/../src/unix; \
	    ${LOCALBASE}/bin/aclocal && ${LOCALBASE}/bin/autoconf

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/squeak/3.0
.for f in ReadMe.txt SqueakV3.sources
	${INSTALL_DATA} ${WRKDIR}/${f} ${PREFIX}/share/squeak/
.endfor
.for f in Squeak3.0.changes Squeak3.0.image
	${INSTALL_DATA} ${WRKDIR}/${f} \
		${PREFIX}/share/squeak/3.0/${f}
.endfor

.include "../../mk/bsd.pkg.mk"
