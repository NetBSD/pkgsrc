# $NetBSD: Makefile,v 1.13 2001/02/17 09:07:12 agc Exp $

DISTNAME=	hugs98-Feb2000
PKGNAME=	hugs98-200002
CATEGORIES=	lang
MASTER_SITES=	ftp://www.cse.ogi.edu/pub/pacsoft/hugs/

MAINTAINER=	nathanw@mit.edu
HOMEPAGE=	http://www.haskell.org/hugs/
COMMENT=	Nottingham and Yale Haskell interpreter and programming environment

DEPENDS+=	readline-*:../../devel/readline

WRKSRC=		${WRKDIR}/hugs98/src
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
