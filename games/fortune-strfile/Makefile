# $NetBSD: Makefile,v 1.1.1.1 2002/10/01 10:31:51 drochner Exp $

DISTNAME=	fortune-strfile-0
CATEGORIES=	games
DISTFILES=	# empty

MAINTAINER=	packages@netbsd.org
COMMENT=	tool to prepare a fortune database

WRKSRC=		${WRKDIR}
NO_CHECKSUM=	yes

# we depend on the "make" infrastructure
ONLY_FOR_PLATFORM= NetBSD-*

do-extract:
	${CP} ${FILESDIR}/strfile.* ${FILESDIR}/Makefile ${WRKSRC}

.include "../../mk/bsd.pkg.mk"
