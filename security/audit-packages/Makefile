# $NetBSD: Makefile,v 1.26 2003/08/22 10:11:57 agc Exp $

DISTNAME=	audit-packages-1.17
WRKSRC=		${WRKDIR}
CATEGORIES=	security pkgtools
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	agc@NetBSD.org
COMMENT=	Tools to show vulnerabilities in installed packages

NO_CHECKSUM=    yes

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "SunOS"
# This doesn't create readable manual pages. "mandoc" should be added
# to zoularis.
NROFF=		nroff -man
.else
NROFF=		nroff -mandoc
.endif

do-build:
	@for f in audit-packages audit-packages.8 \
		download-vulnerability-list; do	\
		${SED} -e 's|@PKGVULNDIR@|${PKGVULNDIR}|g' 		\
			-e 's|@AWK@|${AWK}|g'				\
			-e 's|@FETCH_CMD@|${FETCH_CMD}|g'		\
			-e 's|@FETCH_CMD_SHORT@|${FETCH_CMD:T}|g'	\
			-e 's|@PKGSRCDIR@|${_PKGSRCDIR}|g'		\
			-e 's|@PKG_TOOLS_BIN@|${PKG_TOOLS_BIN}|g'	\
			-e 's|@SH@|${SH}|g'				\
			-e 's|@WC@|${WC}|g'				\
			${FILESDIR}/$$f > ${WRKSRC}/$$f;		\
	done
	${NROFF} ${WRKSRC}/audit-packages.8 >${WRKSRC}/audit-packages.0

do-install:
	@for f in audit-packages download-vulnerability-list; do	\
		${INSTALL_SCRIPT} ${WRKSRC}/$$f ${PREFIX}/sbin;	\
	done
	${INSTALL_MAN} ${WRKSRC}/audit-packages.0 ${PREFIX}/man/cat8
	${INSTALL_MAN} ${WRKSRC}/audit-packages.8 ${PREFIX}/man/man8
	${LN} -sf audit-packages.0 ${PREFIX}/man/cat8/download-vulnerability-list.0
	${LN} -sf audit-packages.8 ${PREFIX}/man/man8/download-vulnerability-list.8

.include "../../mk/bsd.pkg.mk"
