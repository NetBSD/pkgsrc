# $NetBSD: Makefile,v 1.69 2006/09/20 14:43:30 rillig Exp $

DISTNAME=	audit-packages-1.43
CATEGORIES=	security pkgtools
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	agc@NetBSD.org
COMMENT=	Tools to show vulnerabilities in installed packages

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_TOOLS+=	digest:run

BUILD_DEFS+=	PKGVULNDIR

WRKSRC=		${WRKDIR}
NO_CHECKSUM=    yes

OWN_DIRS=	${PKGVULNDIR}
MAN8DIR=	${PREFIX}/${PKGMANDIR}/man8
CAT8DIR=	${PREFIX}/${PKGMANDIR}/cat8
INSTALLATION_DIRS=	${CAT8DIR} ${MAN8DIR} sbin

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "DragonFly"
MESSAGE_SRC=	${PKGDIR}/MESSAGE.DragonFly
.else
MESSAGE_SRC=	${PKGDIR}/MESSAGE
.endif

do-build:
	@for f in audit-packages audit-packages.0 audit-packages.8 	\
		download-vulnerability-list; do				\
		${SED} -e 's|@PKGVULNDIR@|${PKGVULNDIR}|g' 		\
			-e 's|@AWK@|${AWK}|g'				\
			-e 's|@FETCH_CMD@|${FETCH_CMD}|g'		\
			-e 's|@FETCH_CMD_SHORT@|${FETCH_CMD:T}|g'	\
			-e 's|@PKGSRCDIR@|${PKGSRCDIR}|g'		\
			-e 's|@PKG_TOOLS_BIN@|${PKG_TOOLS_BIN}|g'	\
			-e 's|@PREFIX@|${PREFIX}|g'			\
			-e 's|@SH@|${SH}|g'				\
			-e 's|@DIGEST@|${DIGEST}|g'			\
			-e 's|@CHMOD@|${CHMOD}|g'			\
			-e 's|@MV@|${MV}|g'				\
			-e 's|@RM@|${RM}|g'				\
			-e 's|@MKDIR@|${MKDIR}|g'			\
			-e 's|@PKG_SYSCONFDIR@|${PKG_SYSCONFDIR}|g'	\
			-e 's|@FIND@|${FIND}|g'				\
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
	${INSTALL_MAN} ${WRKSRC}/audit-packages.0 ${CAT8DIR}/
	${INSTALL_MAN} ${WRKSRC}/audit-packages.8 ${MAN8DIR}/
	${RM} -f ${CAT8DIR}/download-vulnerability-list.0
	${LN} -s audit-packages.0 ${CAT8DIR}/download-vulnerability-list.0
	${RM} -f ${MAN8DIR}/download-vulnerability-list.8
	${LN} -s audit-packages.8 ${MAN8DIR}/download-vulnerability-list.8

.include "../../mk/bsd.pkg.mk"
