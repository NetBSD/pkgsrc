# $NetBSD: Makefile,v 1.23 2003/05/06 17:40:28 jmmv Exp $
# FreeBSD Id: Makefile,v 1.29 1996/12/20 23:46:22 ache Exp
#

DISTNAME=		tracker-5.3
PKGREVISION=		1
WRKSRC=			${WRKDIR}/tracker
CATEGORIES=		audio
MASTER_SITES=		# empty
EXTRACT_SUFX=		.tgz

MAINTAINER=		packages@netbsd.org
COMMENT=		MOD player

RESTRICTED=		"Non-redistributable beta"
NO_BIN_ON_FTP=		${RESTRICTED}
NO_BIN_ON_CDROM=	${RESTRICTED}
NO_SRC_ON_FTP=		${RESTRICTED}
NO_SRC_ON_CDROM=	${RESTRICTED}

MAKE_FLAGS=		MACHINE=netbsd CC=${CC} INSTALL="${INSTALL}" \
		INST_BIN_OPT="-c -s -m ${BINMODE} -o ${BINOWN} -g ${BINGRP}" \
		INST_MAN_OPT="-c -m 644 -o ${BINOWN} -g ${BINGRP}" \
		COMPRESSION_FILE=${PKG_SYSCONFDIR}/compression_methods \
		COMPRESSION_FILE_EG=${EGDIR}/compression_methods

USE_PKGINSTALL=	yes
EGDIR=		${PREFIX}/share/examples/tracker
CONF_FILES=	${EGDIR}/compression_methods ${PKG_SYSCONFDIR}/compression_methods

INFO_FILES=	tracker.info

pre-install:
	cd ${WRKSRC}/Docs && \
	${MAKEINFO} --no-split tracker.texinfo -o tracker.info && \
	${CP} tracker.info ${PREFIX}/info && \
	${RM} -f tracker.info *.orig
	${INSTALL_DATA_DIR} ${EGDIR}

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/tracker
	${CP} -R ${WRKSRC}/Docs/* ${PREFIX}/share/doc/tracker

.include "../../mk/texinfo.mk"
.include "../../mk/bsd.pkg.mk"
