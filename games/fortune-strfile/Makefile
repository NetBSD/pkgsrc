# $NetBSD: Makefile,v 1.3 2003/06/02 01:19:41 jschauma Exp $

DISTNAME=	fortune-strfile-0
WRKSRC=		${WRKDIR}
CATEGORIES=	games
DISTFILES=	# empty

MAINTAINER=	tech-pkg@netbsd.org
COMMENT=	tool to prepare a fortune database

NO_CHECKSUM=	yes

# we depend on the "make" infrastructure
ONLY_FOR_PLATFORM= NetBSD-*

do-extract:
	${CP} ${FILESDIR}/strfile.* ${FILESDIR}/Makefile ${WRKSRC}

.include "../../mk/bsd.pkg.mk"
