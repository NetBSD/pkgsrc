# $NetBSD: Makefile,v 1.18 2003/03/29 12:42:22 jmmv Exp $

DISTNAME=	audit-packages-1.14
WRKSRC=		${WRKDIR}
CATEGORIES=	security pkgtools
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	agc@netbsd.org
COMMENT=	tools to show vulnerabilities in installed packages

NO_CHECKSUM=    yes
NO_BUILD=	yes
NO_MTREE=	yes

PKGVULNDIR?=	${DISTDIR}

do-configure:
	@for f in audit-packages download-vulnerability-list; do	\
		${SED} -e 's|\$${PKGVULNDIR}|${PKGVULNDIR}|g' 		\
			-e 's|\$${AWK}|${AWK}|g'			\
			-e 's|\$${FETCH_CMD}|${FETCH_CMD}|g'		\
			-e 's|\$${PKG_TOOLS_BIN}|${PKG_TOOLS_BIN}|g'	\
			-e 's|\$${SH}|${SH}|g'				\
			-e 's|\$${TOUCH}|${TOUCH}|g'			\
			${FILESDIR}/$$f > ${WRKSRC}/$$f;		\
	done

do-install:
	@for f in audit-packages download-vulnerability-list; do	\
		${INSTALL_SCRIPT} ${WRKSRC}/$$f ${PREFIX}/sbin;	\
	done

.include "../../mk/bsd.pkg.mk"
