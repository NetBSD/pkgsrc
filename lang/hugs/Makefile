# $NetBSD: Makefile,v 1.6 1999/08/18 03:17:20 nathanw Exp $

DISTNAME=	Hugs98-May1999
CATEGORIES=	lang
MASTER_SITES=	http://www.cse.ogi.edu/~mpj/Hugs98/
EXTRACT_SUFX=	.tar.gz

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
