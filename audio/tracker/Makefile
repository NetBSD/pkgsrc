# $NetBSD: Makefile,v 1.32 2005/03/24 21:12:51 wiz Exp $

DISTNAME=		tracker-5.3
PKGREVISION=		1
CATEGORIES=		audio
MASTER_SITES=		# empty
EXTRACT_SUFX=		.tgz

MAINTAINER=		tech-pkg@NetBSD.org
COMMENT=		MOD player

RESTRICTED=		"No commercial redistribution"
NO_BIN_ON_FTP=		${RESTRICTED}
NO_BIN_ON_CDROM=	${RESTRICTED}
NO_SRC_ON_CDROM=	${RESTRICTED}

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_BUILDLINK3=		yes
WRKSRC=			${WRKDIR}/tracker
MAKE_FLAGS=		MACHINE=${LOWER_OPSYS} CC=${CC} INSTALL="${INSTALL}" \
		INST_BIN_OPT="-c -s -m ${BINMODE} -o ${BINOWN} -g ${BINGRP}" \
		INST_MAN_OPT="-c -m 644 -o ${BINOWN} -g ${BINGRP}" \
		COMPRESSION_FILE=${PKG_SYSCONFDIR}/compression_methods \
		COMPRESSION_FILE_EG=${EGDIR}/compression_methods

USE_PKGINSTALL=	yes
EGDIR=		${PREFIX}/share/examples/tracker
CONF_FILES=	${EGDIR}/compression_methods ${PKG_SYSCONFDIR}/compression_methods

USE_MAKEINFO=	YES
INFO_FILES=	tracker.info

INSTALLATION_DIRS=	bin info

.include "../../mk/ossaudio.buildlink3.mk"

pre-install:
	cd ${WRKSRC}/Docs && \
	${MAKEINFO} --no-split tracker.texinfo -o tracker.info && \
	${CP} tracker.info ${PREFIX}/info && \
	${RM} -f tracker.info *.orig
	${INSTALL_DATA_DIR} ${EGDIR}

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/tracker
	${CP} -R ${WRKSRC}/Docs/* ${PREFIX}/share/doc/tracker

.include "../../mk/bsd.pkg.mk"
