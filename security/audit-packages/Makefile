# $NetBSD: Makefile,v 1.31 2003/09/16 07:21:01 agc Exp $

DISTNAME=	audit-packages-1.22
WRKSRC=		${WRKDIR}
CATEGORIES=	security pkgtools
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	agc@NetBSD.org
COMMENT=	Tools to show vulnerabilities in installed packages

NO_CHECKSUM=    yes

DEPENDS+=	digest-[0-9]*:../../pkgtools/digest

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
			-e 's|@DIGEST@|${DIGEST}|g'			\
			-e 's|@CHMOD@|${CHMOD}|g'			\
			-e 's|@MV@|${MV}|g'				\
			-e 's|@RM@|${RM}|g'				\
			-e 's|@MKDIR@|${MKDIR}|g'			\
			${FILESDIR}/$$f > ${WRKSRC}/$$f;		\
	done
	${NROFF} ${WRKSRC}/audit-packages.8 >${WRKSRC}/audit-packages.0

do-install:
	@for f in audit-packages download-vulnerability-list; do	\
		${INSTALL_SCRIPT} ${WRKSRC}/$$f ${PREFIX}/sbin;		\
	done
	${INSTALL_MAN} ${WRKSRC}/audit-packages.0 ${PREFIX}/man/cat8
	${INSTALL_MAN} ${WRKSRC}/audit-packages.8 ${PREFIX}/man/man8
	${RM} -f ${PREFIX}/man/cat8/download-vulnerability-list.0
	${LN} -s audit-packages.0 ${PREFIX}/man/cat8/download-vulnerability-list.0
	${RM} -f ${PREFIX}/man/man8/download-vulnerability-list.8
	${LN} -s audit-packages.8 ${PREFIX}/man/man8/download-vulnerability-list.8

.include "../../mk/bsd.pkg.mk"
