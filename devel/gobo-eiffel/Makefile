# $NetBSD: Makefile,v 1.19 2008/05/26 02:13:17 joerg Exp $
#

DISTNAME=	gobo15
PKGNAME=	gobo-eiffel-1.5
PKGREVISION=	3
CATEGORIES=	devel
MASTER_SITES=	ftp://ftp.eiffel.com/pub/shelf/bezault/
EXTRACT_SUFX=	.zip

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.gobosoft.com/
COMMENT=	Portable Eiffel structure libraries and tools

PKG_DESTDIR_SUPPORT=	user-destdir

BUILD_DEPENDS+=	SmartEiffel-[0-9]*:../../lang/SmartEiffel
USE_TOOLS+=	pax

EXTRACT_OPTS_ZIP=	-uLa

WRKSRC=		${WRKDIR}
GOBO=		${PREFIX}/share/gobo-eiffel

INSTALLATION_DIRS+=	bin share/gogo-eiffel share/doc/gogo-eiffel
INSTALLATION_DIRS+=	share/examples/gobo-eiffel

post-extract:
	${RM} -rf ${WRKSRC}/bin
	for dir in doc example library; do 				\
	${FIND} ${WRKSRC}/$$dir ! -type d | ${XARGS} ${CHMOD} 644;	\
	${FIND} ${WRKSRC}/$$dir -type d | ${XARGS} ${CHMOD} 755;	\
	done

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
	${INSTALL_PROGRAM} ${WRKSRC}/src/gelex/a.out ${DESTDIR}${PREFIX}/bin/gelex
	${INSTALL_PROGRAM} ${WRKSRC}/src/gepp/a.out ${DESTDIR}${PREFIX}/bin/gepp
	${INSTALL_PROGRAM} ${WRKSRC}/src/geyacc/a.out ${DESTDIR}${PREFIX}/bin/geyacc
	cd ${WRKSRC}; pax -rw library ${DESTDIR}${GOBO}
	${CHOWN} ${SHAREOWN}:${SHAREGRP} ${DESTDIR}${GOBO}
	cd ${WRKSRC}/doc; pax -rw * ${DESTDIR}${PREFIX}/share/doc/gobo-eiffel
	${CHOWN} ${SHAREOWN}:${SHAREGRP} ${DESTDIR}${PREFIX}/share/doc/gobo-eiffel
	cd ${WRKSRC}/example; pax -rw * ${DESTDIR}${PREFIX}/share/examples/gobo-eiffel
	${CHOWN} ${SHAREOWN}:${SHAREGRP} ${DESTDIR}${PREFIX}/share/examples/gobo-eiffel

.include "../../mk/bsd.pkg.mk"
