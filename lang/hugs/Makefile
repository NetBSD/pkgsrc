# $NetBSD: Makefile,v 1.11 2000/04/24 04:17:38 mbw Exp $

DISTNAME=	Hugs98-May1999
PKGNAME=	Hugs98-199905
CATEGORIES=	lang
MASTER_SITES=	http://www.cse.ogi.edu/~mpj/Hugs98/

MAINTAINER=	nathanw@mit.edu
HOMEPAGE=	http://www.haskell.org/hugs/

DEPENDS+=	readline-*:../../devel/readline

WRKSRC=		${WRKDIR}/Hugs98/src
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=--with-readline

ALL_TARGET=	default
MAKE_ENV=	INSTALL="${INSTALL}" INSTALL_DATA="${INSTALL_DATA}" \
		INSTALL_PROGRAM="${INSTALL_PROGRAM}"

do-configure:
	cd ${WRKSRC}; (cd unix; ./${CONFIGURE_SCRIPT} ${CONFIGURE_ARGS})

post-install:
	${INSTALL_DATA} ${WRKSRC}/../docs/hugs.1 ${PREFIX}/man/man1/hugs.1

.include "../../mk/bsd.pkg.mk"
