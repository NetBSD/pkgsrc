# $NetBSD: Makefile,v 1.4 2003/07/17 21:38:21 grant Exp $

DISTNAME=	fortune-strfile-0
WRKSRC=		${WRKDIR}
CATEGORIES=	games
DISTFILES=	# empty

MAINTAINER=	tech-pkg@NetBSD.org
COMMENT=	tool to prepare a fortune database

NO_CHECKSUM=	yes

# we depend on the "make" infrastructure
ONLY_FOR_PLATFORM= NetBSD-*

do-extract:
	${CP} ${FILESDIR}/strfile.* ${FILESDIR}/Makefile ${WRKSRC}

.include "../../mk/bsd.pkg.mk"
