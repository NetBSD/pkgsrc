# $NetBSD: Makefile,v 1.23 2005/05/17 08:41:36 schmonz Exp $

DISTNAME=		daemontools-0.76
CATEGORIES=		sysutils
MASTER_SITES=		http://cr.yp.to/daemontools/ ftp://cr.yp.to/daemontools/
DISTFILES=		${DISTNAME}${EXTRACT_SUFX} ${MANPAGES}

MAINTAINER=		schmonz@NetBSD.org
HOMEPAGE=		http://cr.yp.to/daemontools.html
COMMENT=		Service monitoring and logging utilities by djb

MANPAGES=		${DISTNAME}-man-20020131.tar.gz
SITES_${MANPAGES}=	http://smarden.org/pape/djb/manpages/

DJB_RESTRICTED=		YES

PKG_INSTALLATION_TYPES=	overwrite pkgviews

.if defined(PKG_PHASE) && ${PKG_PHASE} == "configure"
WRKSRC=			${WRKDIR}/admin/${DISTNAME}/src
.else
WRKSRC=			${WRKDIR}/admin/${DISTNAME}
.endif

SAMPLERC=		svscan.sh.sample
SERVICEDIR?=		${VARBASE}/spool/service
CMDDIR=			${WRKSRC}/command

PLIST_SUBST+=		SERVICEDIR=${SERVICEDIR}
DEINSTALL_FILE=		${WRKDIR}/.DEINSTALL

INSTALLATION_DIRS=	bin man man/man8 share/examples/daemontools

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
	cd ${WRKDIR}/*-man; for i in 8; do		 		\
	for j in *.$$i; do ${INSTALL_MAN} $$j ${PREFIX}/man/man$$i; done \
	done

.include "../../mk/djbware.mk"
.include "../../mk/bsd.pkg.mk"
