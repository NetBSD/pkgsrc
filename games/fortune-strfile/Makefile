# $NetBSD: Makefile,v 1.9 2006/06/08 16:21:17 minskim Exp $

DISTNAME=	fortune-strfile-0
CATEGORIES=	games
DISTFILES=	# empty

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Tool to prepare a fortune database

WRKSRC=		${WRKDIR}
NO_CHECKSUM=	yes

MAKE_ENV+=	BINOWN=${BINOWN} BINGRP=${BINGRP} BINMODE=${BINMODE}
MAKE_ENV+=	MANOWN=${MANOWN} MANGRP=${MANGRP} MANMODE=${MANMODE}

do-extract:
	${CP} ${FILESDIR}/strfile.* ${FILESDIR}/Makefile ${WRKSRC}

.include "../../mk/bsd.pkg.mk"
