# $NetBSD: Makefile,v 1.11 2004/04/24 22:46:09 jlam Exp $
#

DISTNAME=	gobo15
PKGNAME=	gobo-eiffel-1.5
CATEGORIES=	devel
MASTER_SITES=	http://www.gobosoft.com/download/ \
		http://www.eiffel-forum.org/archive/bezault/ \
		ftp://ftp.eiffel.com/pub/shelf/bezault/
EXTRACT_SUFX=	.zip

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.gobosoft.com/
COMMENT=	Portable Eiffel structure libraries and tools

BUILD_DEPENDS+=	smalleiffel-0.77:../../lang/smalleiffel

WRKSRC=		${WRKDIR}
EXTRACT_CMD=	${LOCALBASE}/bin/unzip -uLa \
			${DISTDIR}/${DISTNAME}${EXTRACT_SUFX}

GOBO=		${PREFIX}/share/gobo-eiffel

post-extract:
	${RM} -rf ${WRKSRC}/bin

pre-build:
	for file in `${FIND} ${WRKSRC} -name "se.sh" -print`; do \
		${SED} -e "s,compile,smalleiffel compile -verbose -O2," \
			$${file} > $${file}.tmp; \
		${RM} -f $${file}; \
		${MV} -f $${file}.tmp $${file}; \
	done

do-build:
	cd ${WRKSRC}/src/gelex; GOBO=${WRKSRC} ${SH} se.sh
	cd ${WRKSRC}/src/gepp; GOBO=${WRKSRC} ${SH} se.sh
	cd ${WRKSRC}/src/geyacc; GOBO=${WRKSRC} ${SH} se.sh

pre-install:
	for file in `${FIND} ${WRKSRC} -name "loadpath.se" -print`; do \
		${SED} -e "s,\$${GOBO},${GOBO}," $${file} > $${file}.tmp; \
		${RM} -f $${file}; \
		${MV} -f $${file}.tmp $${file}; \
	done

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/gelex/a.out ${PREFIX}/bin/gelex
	${INSTALL_PROGRAM} ${WRKSRC}/src/gepp/a.out ${PREFIX}/bin/gepp
	${INSTALL_PROGRAM} ${WRKSRC}/src/geyacc/a.out ${PREFIX}/bin/geyacc
	${INSTALL_DATA_DIR} ${GOBO}
	cd ${WRKSRC}; ${PAX} -rw library ${GOBO}
	${CHOWN} ${SHAREOWN}:${SHAREGRP} ${GOBO}
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/gobo-eiffel
	cd ${WRKSRC}/doc; ${PAX} -rw * ${PREFIX}/share/doc/gobo-eiffel
	${CHOWN} ${SHAREOWN}:${SHAREGRP} ${PREFIX}/share/doc/gobo-eiffel
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/gobo-eiffel
	cd ${WRKSRC}/example; ${PAX} -rw * ${PREFIX}/share/examples/gobo-eiffel
	${CHOWN} ${SHAREOWN}:${SHAREGRP} ${PREFIX}/share/examples/gobo-eiffel

.include "../../mk/bsd.pkg.mk"
