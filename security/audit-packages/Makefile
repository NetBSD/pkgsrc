# $NetBSD: Makefile,v 1.50 2004/10/07 02:01:38 jlam Exp $

DISTNAME=	audit-packages-1.32
CATEGORIES=	security pkgtools
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	agc@NetBSD.org
COMMENT=	Tools to show vulnerabilities in installed packages

PKG_INSTALLATION_TYPES=	overwrite pkgviews

DEPENDS+=	digest-[0-9]*:../../pkgtools/digest

WRKSRC=		${WRKDIR}
NO_CHECKSUM=    yes
NO_BUILDLINK=	yes

INSTALLATION_DIRS=	man/cat8 man/man8 sbin

.include "../../mk/bsd.prefs.mk"

do-build:
	@for f in audit-packages audit-packages.0 audit-packages.8 	\
		download-vulnerability-list; do				\
		${SED} -e 's|@PKGVULNDIR@|${PKGVULNDIR}|g' 		\
			-e 's|@AWK@|${AWK}|g'				\
			-e 's|@FETCH_CMD@|${FETCH_CMD}|g'		\
			-e 's|@FETCH_CMD_SHORT@|${FETCH_CMD:T}|g'	\
			-e 's|@PKGSRCDIR@|${PKGSRCDIR}|g'		\
			-e 's|@PKG_TOOLS_BIN@|${PKG_TOOLS_BIN}|g'	\
			-e 's|@SH@|${SH}|g'				\
			-e 's|@DIGEST@|${DIGEST}|g'			\
			-e 's|@CHMOD@|${CHMOD}|g'			\
			-e 's|@MV@|${MV}|g'				\
			-e 's|@RM@|${RM}|g'				\
			-e 's|@MKDIR@|${MKDIR}|g'			\
			-e 's|@PKG_SYSCONFDIR@|${PKG_SYSCONFDIR}|g'	\
			${FILESDIR}/$$f > ${WRKSRC}/$$f;		\
	done
.if ${OPSYS} == "SunOS" || ${OPSYS} == "AIX"
	# pre-created man-pages are "mandoc" pages, these OS need "man",
	# so regen the .0 page
	nroff -man ${WRKSRC}/audit-packages.8 >${WRKSRC}/audit-packages.0
.endif

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
