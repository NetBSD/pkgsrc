# $NetBSD: Makefile,v 1.11 2007/01/07 13:39:44 rillig Exp $

DISTNAME=	fortune-strfile-0
CATEGORIES=	games
DISTFILES=	# empty

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Tool to prepare a fortune database

WRKSRC=		${WRKDIR}
NO_CHECKSUM=	yes
USE_BSD_MAKEFILE=	yes

do-extract:
	cp ${FILESDIR}/strfile.* ${FILESDIR}/Makefile ${WRKSRC}

.include "../../mk/bsd.pkg.mk"
