# $NetBSD: Makefile,v 1.20 2003/05/21 14:07:45 seb Exp $

DISTNAME=	audit-packages-1.15
WRKSRC=		${WRKDIR}
CATEGORIES=	security pkgtools
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	agc@netbsd.org
COMMENT=	tools to show vulnerabilities in installed packages

NO_CHECKSUM=    yes
NO_BUILD=	yes
NO_MTREE=	yes

do-configure:
	@for f in audit-packages download-vulnerability-list; do	\
		${SED} -e 's|@PKGVULNDIR@|${PKGVULNDIR}|g' 		\
			-e 's|@AWK@|${AWK}|g'				\
			-e 's|@FETCH_CMD@|${FETCH_CMD}|g'		\
			-e 's|@PKG_TOOLS_BIN@|${PKG_TOOLS_BIN}|g'	\
			-e 's|@SH@|${SH}|g'				\
			${FILESDIR}/$$f > ${WRKSRC}/$$f;		\
	done

do-install:
	@for f in audit-packages download-vulnerability-list; do	\
		${INSTALL_SCRIPT} ${WRKSRC}/$$f ${PREFIX}/sbin;	\
	done

.include "../../mk/bsd.pkg.mk"
