# $NetBSD: Makefile,v 1.20 2005/03/24 21:13:01 wiz Exp $

DISTNAME=		daemontools-0.76
CATEGORIES=		sysutils
MASTER_SITES=		http://cr.yp.to/daemontools/			\
			ftp://cr.yp.to/daemontools/			\
			http://smarden.org/pape/djb/manpages/
DISTFILES=		${DISTNAME}.tar.gz				\
			${DISTNAME}-man.tar.gz

MAINTAINER=		schmonz@NetBSD.org
HOMEPAGE=		http://cr.yp.to/daemontools.html
COMMENT=		Service monitoring and logging utilities by djb

DJB_RESTRICTED=		YES

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_BUILDLINK3=		yes

SAMPLERC=		svscan.sh.sample
SERVICEDIR?=		${VARBASE}/spool/service
WRKSRC=			${WRKDIR}/admin/${DISTNAME}
CMDDIR=			${WRKSRC}/command

PLIST_SUBST+=		SERVICEDIR=${SERVICEDIR}
DEINSTALL_FILE=		${WRKDIR}/.DEINSTALL

INSTALLATION_DIRS=	bin man man/man8 share/examples/daemontools

DJB_CONFIG_DIR=		${WRKSRC}/src

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

.include "../../mk/djbware.mk"
.include "../../mk/bsd.pkg.mk"
