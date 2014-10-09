# $NetBSD: Makefile,v 1.46 2014/10/09 14:05:58 wiz Exp $

DISTNAME=		tracker-5.3
PKGREVISION=		1
CATEGORIES=		audio
MASTER_SITES=		# empty
EXTRACT_SUFX=		.tgz

MAINTAINER=		pkgsrc-users@NetBSD.org
COMMENT=		MOD player

RESTRICTED=		No commercial redistribution
NO_BIN_ON_FTP=		${RESTRICTED}
NO_BIN_ON_CDROM=	${RESTRICTED}
NO_SRC_ON_CDROM=	${RESTRICTED}

MAKE_JOBS_SAFE=		no

WRKSRC=			${WRKDIR}/tracker
MAKE_FLAGS+=		MACHINE=${LOWER_OPSYS:Q} INSTALL=${INSTALL:Q} \
		COMPRESSION_FILE=${PKG_SYSCONFDIR}/compression_methods \
		COMPRESSION_FILE_EG=${EGDIR}/compression_methods

EGDIR=		${PREFIX}/share/examples/tracker
CONF_FILES=	${EGDIR}/compression_methods ${PKG_SYSCONFDIR}/compression_methods

USE_TOOLS+=	makeinfo
INFO_FILES=	YES

INSTALLATION_DIRS=	bin ${PKGINFODIR} ${EGDIR}

.include "../../mk/oss.buildlink3.mk"

post-build:
	cd ${WRKSRC}/Docs &&						\
	${MAKEINFO} tracker.texinfo &&					\
	${MV} -f tracker.info* ${WRKDIR} &&				\
	${RM} *.orig

post-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/doc/tracker
	${CP} -R ${WRKSRC}/Docs/* ${DESTDIR}${PREFIX}/share/doc/tracker
	${INSTALL_DATA} ${WRKDIR}/tracker.info* ${DESTDIR}${PREFIX}/${PKGINFODIR}

.include "../../mk/bsd.pkg.mk"
