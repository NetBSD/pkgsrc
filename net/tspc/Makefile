# $NetBSD: Makefile,v 1.1.1.1 2002/08/22 18:14:51 grant Exp $
#

DISTNAME=	freenet6-0.9.6
PKGNAME=	tspc-0.9.6
CATEGORIES=	net
MASTER_SITES=	# empty
EXTRACT_SUFX=	.tgz

MAINTAINER=	grant@netbsd.org
HOMEPAGE=	http://www.freenet6.net/
COMMENT=	freenet6 IPv6 tunnel server protocol client

NO_CONFIGURE=		yes
INTERACTIVE_STAGE=	fetch
ONLY_FOR_PLATFORM=	NetBSD-*-* Linux-*-* SunOS-5.[8-9]-*

.include "../../mk/bsd.prefs.mk"
.if ${OPSYS} == "SunOS"
TARGET=		${LOWER_OPSYS}8
.else
TARGET=		${LOWER_OPSYS}
.endif

ALL_TARGET=	all target="${TARGET}"
INSTALL_TARGET=	${ALL_TARGET}

DOWNLOAD=	http://www.freenet6.net/cgi-bin/download.cgi?fn=${DISTNAME}${EXTRACT_SUFX}

_FETCH_MESSAGE= \
	${ECHO} "==============================================================="; \
	${ECHO} "  The Freenet6 client must be fetched"; \
	${ECHO} "  into ${DISTDIR} from"; \
	${ECHO} "  ${DOWNLOAD}."; \
	${ECHO} "==============================================================="

TSP_DIR=	${PREFIX}/share/tspc
CONF_FILES=	${WRKSRC}/bin/tspc.conf ${PREFIX}/etc/tspc.conf

pre-build:
.for file in src/Makefile src/tspc.c man/man8/tspc.8
	${MV} ${WRKSRC}/${file} ${WRKSRC}/${file}.orig
	${SED} -e 's|@PREFIX@|${PREFIX}|' ${WRKSRC}/${file}.orig > \
		${WRKSRC}/${file}
.endfor
.for file in src/tspc.c src/tspc.conf.in
	${MV} ${WRKSRC}/${file} ${WRKSRC}/${file}.orig
	${SED} -e 's|@TSP_DIR@|${TSP_DIR}|' ${WRKSRC}/${file}.orig > \
		${WRKSRC}/${file}
.endfor

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bin/tspc ${PREFIX}/sbin
	${INSTALL_MAN} ${WRKSRC}/man/man5/tspc.conf.5 ${PREFIX}/man/man5
	${INSTALL_MAN} ${WRKSRC}/man/man8/tspc.8 ${PREFIX}/man/man8
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/tspc
	${INSTALL_DATA} ${WRKSRC}/CONTRIB.txt ${PREFIX}/share/doc/tspc
	${INSTALL_DATA} ${WRKSRC}/LEGAL ${PREFIX}/share/doc/tspc
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/tspc
	${INSTALL_DATA_DIR} ${PREFIX}/share/tspc
	${INSTALL_DATA_DIR} ${PREFIX}/share/tspc/template
.for template in checktunnel.sh cisco.sh freebsd4.sh freebsd44.sh linux.sh netbsd.sh openbsd.sh solaris8.sh
	${INSTALL_SCRIPT} ${WRKSRC}/template/${template} ${PREFIX}/share/tspc/template
.endfor

.include "../../mk/bsd.pkg.install.mk"
.include "../../mk/bsd.pkg.mk"
