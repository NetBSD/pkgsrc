# $NetBSD: Makefile,v 1.5 1998/10/11 21:17:01 kim Exp $

DISTNAME=	ntop-1.0
CATEGORIES=	net
MASTER_SITES=	${HOMEPAGE}/download/source/
EXTRACT_SUFX=	.src.tar.gz

MAINTAINER=	kim@tac.nyc.ny.us

BUILD_DEPENDS+=	autoconf:../../devel/autoconf
DEPENDS+=	ncurses-1.9.9g:../../devel/ncurses

HOMEPAGE=	http://www-serra.unipi.it/~ntop/

NOT_FOR_ARCHS=	alpha mips # elf problems WRT libcurses

HAS_CONFIGURE=	yes
GNU_CONFIGURE=	yes

LDFLAGS+=	-L${PREFIX}/lib

CONFIGURE_ENV+=	CPPFLAGS=-I${PREFIX}/include
CONFIGURE_ENV+=	CFLAGS=-I${PREFIX}/include
CONFIGURE_ENV+=	LDFLAGS=-L${PREFIX}/lib

pre-configure:
	(cd ${WRKSRC}; autoconf)

.include "../../mk/bsd.pkg.mk"
