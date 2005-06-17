# $NetBSD: Makefile,v 1.8 2005/06/17 03:50:28 jlam Exp $
#

DISTNAME=	freenet6-client-1.0
PKGNAME=	${DISTNAME:S/freenet6-client/tspc/}
CATEGORIES=	net
MASTER_SITES=	# empty
EXTRACT_SUFX=	.tgz

MAINTAINER=	grant@NetBSD.org
HOMEPAGE=	http://www.freenet6.net/
COMMENT=	Freenet6 IPv6 tunnel server protocol client

USE_PKGINSTALL=		yes
NO_CONFIGURE=		yes
INTERACTIVE_STAGE=	fetch
ONLY_FOR_PLATFORM=	NetBSD-*-* Linux-*-* SunOS-5.[8-9]-* Darwin-*-*

.include "../../mk/bsd.prefs.mk"
.if ${OPSYS} == "SunOS"
TARGET=		${LOWER_OPSYS}8
.else
TARGET=		${LOWER_OPSYS}
.endif

BUILD_TARGET=	all target="${TARGET}"
INSTALL_TARGET=	${ALL_TARGET}

DOWNLOAD=	http://www.freenet6.net/cgi-bin/download.cgi?fn=${DISTNAME}${EXTRACT_SUFX}

_FETCH_MESSAGE= \
	${ECHO} "==============================================================="; \
	${ECHO} "  The Freenet6 client must be fetched"; \
	${ECHO} "  into ${DISTDIR} from"; \
	${ECHO} "  ${DOWNLOAD}."; \
	${ECHO} "==============================================================="

FILES_SUBST+=	TSP_DIR=${PREFIX}/share/tspc
EGDIR=		${PREFIX}/share/examples/tspc
CONF_FILES=	${EGDIR}/tspc.conf.default ${PKG_SYSCONFDIR}/tspc.conf

INSTALLATION_DIRS=	man/man5 man/man8 sbin

pre-build:
.for f in man/man5/tspc.conf.5 man/man8/tspc.8 src/Makefile	\
	src/tspc.c src/tspc.c src/tspc.conf.in
	@${MV} ${WRKSRC}/${f} ${WRKSRC}/${f}.orig
	@${SED} ${FILES_SUBST_SED} ${WRKSRC}/${f}.orig > ${WRKSRC}/${f}
.endfor

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bin/tspc ${PREFIX}/sbin
	${INSTALL_MAN} ${WRKSRC}/man/man5/tspc.conf.5 ${PREFIX}/man/man5
	${INSTALL_MAN} ${WRKSRC}/man/man8/tspc.8 ${PREFIX}/man/man8
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/tspc
	${INSTALL_DATA} ${WRKSRC}/bin/tspc.conf ${EGDIR}/tspc.conf.default
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/tspc
	${INSTALL_DATA} ${WRKSRC}/CONTRIB.txt ${PREFIX}/share/doc/tspc
	${INSTALL_DATA} ${WRKSRC}/LEGAL ${PREFIX}/share/doc/tspc
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/tspc
	${INSTALL_DATA_DIR} ${PREFIX}/share/tspc
	${INSTALL_DATA_DIR} ${PREFIX}/share/tspc/template
	cd ${WRKSRC}/template &&					\
	${INSTALL_SCRIPT} checktunnel.sh cisco.sh darwin.sh freebsd4.sh	\
		freebsd44.sh linux.sh netbsd.sh openbsd.sh solaris8.sh	\
		${PREFIX}/share/tspc/template

.include "../../mk/bsd.pkg.mk"
