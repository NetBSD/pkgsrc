# $NetBSD: Makefile,v 1.18 2002/02/18 15:14:02 seb Exp $
# FreeBSD Id: Makefile,v 1.29 1996/12/20 23:46:22 ache Exp 
#

DISTNAME=		tracker-5.3
CATEGORIES=		audio
MASTER_SITES=		ftp://ftp.uni-trier.de/pub/unix/audio/tracker/
EXTRACT_SUFX=		.tgz

MAINTAINER=		packages@netbsd.org
COMMENT=		MOD player

RESTRICTED=		"Non-redistributable beta"
NO_BIN_ON_FTP=		${RESTRICTED}
NO_BIN_ON_CDROM=	${RESTRICTED}
NO_SRC_ON_FTP=		${RESTRICTED}
NO_SRC_ON_CDROM=	${RESTRICTED}

WRKSRC=			${WRKDIR}/tracker
MAKE_FLAGS=		MACHINE=netbsd CC=${CC} INSTALL="${INSTALL}" \
		INST_BIN_OPT="-c -s -m ${BINMODE} -o ${BINOWN} -g ${BINGRP}" \
		INST_MAN_OPT="-c -m 644 -o ${BINOWN} -g ${BINGRP}" \
		COMPRESSION_FILE=${PREFIX}/etc/compression_methods

INFO_FILES=		tracker.info

pre-install:
	cd ${WRKSRC}/Docs && \
	${MAKEINFO} --no-split tracker.texinfo -o tracker.info && \
	${CP} tracker.info ${PREFIX}/info && \
	${RM} -f tracker.info *.orig

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/tracker
	${CP} -R ${WRKSRC}/Docs/* ${PREFIX}/share/doc/tracker

.include "../../mk/texinfo.mk"
.include "../../mk/bsd.pkg.mk"
