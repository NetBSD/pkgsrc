# $NetBSD: Makefile,v 1.10 2001/04/27 08:40:53 agc Exp $

DISTNAME=	audit-packages-1.8
CATEGORIES=	security pkgtools
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	agc@netbsd.org
COMMENT=	tools to show vulnerabilities in installed packages

WRKSRC=		${WRKDIR}
NO_CHECKSUM=    yes
NO_BUILD=	yes
NO_MTREE=	yes

do-configure:
	@for f in audit-packages download-vulnerability-list; do	\
		${SED} -e 's|\$${DISTDIR}|${DISTDIR}|g' 		\
			-e 's|\$${AWK}|${AWK}|g'			\
			-e 's|\$${FETCH_CMD}|${FETCH_CMD}|g'		\
			-e 's|\$${PKG_INFO}|${PKG_INFO}|g'		\
			-e 's|\$${TOUCH}|${TOUCH}|g'			\
			${FILESDIR}/$$f > ${WRKSRC}/$$f;		\
	done

do-install:
	@for f in audit-packages download-vulnerability-list; do	\
		${BSD_INSTALL_SCRIPT} ${WRKSRC}/$$f ${PREFIX}/sbin;	\
	done

.include "../../mk/bsd.pkg.mk"
