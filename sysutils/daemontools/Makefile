# $NetBSD: Makefile,v 1.16 2004/12/03 15:15:10 wiz Exp $
# FreeBSD Id: ports/sysutils/daemontools/Makefile,v 1.8 2000/12/03 05:16:41 steve Exp

DISTNAME=	daemontools-0.76
CATEGORIES=	sysutils
MASTER_SITES=	http://cr.yp.to/daemontools/				\
		ftp://cr.yp.to/daemontools/				\
		http://smarden.org/pape/djb/manpages/
DISTFILES=	${DISTNAME}.tar.gz					\
		${DISTNAME}-man.tar.gz

MAINTAINER=	schmonz@NetBSD.org
HOMEPAGE=	http://cr.yp.to/daemontools.html
COMMENT=	Service monitoring and logging utilities by djb

RESTRICTED=	"modified source and binaries may not be distributed"
NO_BIN_ON_CDROM=${RESTRICTED}
NO_BIN_ON_FTP=	${RESTRICTED}

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_BUILDLINK3=	yes

BUILD_TARGET=	it
SAMPLERC=	svscan.sh.sample
SERVICEDIR?=	${VARBASE}/spool/service
WRKSRC=		${WRKDIR}/admin/${DISTNAME}
CMDDIR=		${WRKSRC}/command

PLIST_SUBST+=	SERVICEDIR=${SERVICEDIR}
DEINSTALL_FILE=	${WRKDIR}/.DEINSTALL

INSTALLATION_DIRS=	bin man man/man8 share/examples/daemontools

do-configure:
	@${ECHO} ${CC} ${CFLAGS} > ${WRKSRC}/src/conf-cc
	@${ECHO} ${CC} ${_STRIPFLAG_CC} > ${WRKSRC}/src/conf-ld
	@${ECHO} ${PREFIX} > ${WRKSRC}/src/conf-home

do-build:
	cd ${WRKSRC} && package/compile

post-build:
	${SED}	-e "s,@@PREFIX@@,${PREFIX},"				\
		-e "s,@@SERVICEDIR@@,${SERVICEDIR},g"			\
		${FILESDIR}/${SAMPLERC} > ${WRKDIR}/${SAMPLERC}
	${SED}	"s,@@SERVICEDIR@@,${SERVICEDIR},g"			\
		${PKGDIR}/DEINSTALL > ${DEINSTALL_FILE}

do-install:
	(while read cmd; do \
	  if ${FILE_CMD} ${CMDDIR}/$$cmd | ${EGREP} "(executable .* script|shell script|text)" >/dev/null 2>&1; then \
	    ${INSTALL_SCRIPT} ${CMDDIR}/$$cmd ${PREFIX}/bin; \
	  else \
	    ${INSTALL_PROGRAM} ${CMDDIR}/$$cmd ${PREFIX}/bin; \
	  fi \
	done) < ${WRKSRC}/package/commands

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/daemontools
	${INSTALL_DATA} ${WRKDIR}/${SAMPLERC}				\
		${PREFIX}/share/examples/daemontools
	${INSTALL_DATA_DIR} ${SERVICEDIR}
	cd ${WRKDIR}/${PKGBASE}-man && ${INSTALL_MAN} *.8 ${PREFIX}/man/man8

.include "../../mk/bsd.pkg.mk"
