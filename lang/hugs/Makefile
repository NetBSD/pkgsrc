# $NetBSD: Makefile,v 1.7 1999/08/18 10:19:40 agc Exp $

DISTNAME=	Hugs98-May1999
CATEGORIES=	lang
MASTER_SITES=	http://www.cse.ogi.edu/~mpj/Hugs98/

MAINTAINER=	nathanw@mit.edu
HOMEPAGE=	http://www.haskell.org/hugs/

WRKSRC=		${WRKDIR}/Hugs98/src
GNU_CONFIGURE=	yes
ALL_TARGET=	default
MAKE_ENV=	INSTALL="${INSTALL}" INSTALL_DATA="${INSTALL_DATA}" \
		INSTALL_PROGRAM="${INSTALL_PROGRAM}"

do-configure:
	cd ${WRKSRC}; (cd unix; ./${CONFIGURE_SCRIPT} ${CONFIGURE_ARGS})

post-install:
	${INSTALL_DATA} ${WRKSRC}/../docs/hugs.1 ${PREFIX}/man/man1/hugs.1

.include "../../mk/bsd.pkg.mk"
