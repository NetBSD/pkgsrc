# $NetBSD: Makefile,v 1.3 1998/09/22 06:11:39 garbled Exp $

DISTNAME=	ntop-0.4-src
PKGNAME=	ntop-0.4
WRKSRC=		${WRKDIR}/${PKGNAME}
CATEGORIES=	net
MASTER_SITES=	http://jake.unipi.it/~deri/ntop/

NOT_FOR_ARCHS=	alpha mips # elf problems WRT libcurses

MAINTAINER=	kim@tac.nyc.ny.us
HOMEPAGE=	http://jake.unipi.it/~deri/ntop/

DEPENDS+=	autoconf-2.12:../../devel/autoconf
DEPENDS+=	ncurses-1.9.9g:../../devel/ncurses

HAS_CONFIGURE=	yes
GNU_CONFIGURE=	yes

CONFIGURE_ENV+=	CPPFLAGS=-I${PREFIX}/include
CONFIGURE_ENV+=	CFLAGS=-I${PREFIX}/include
CONFIGURE_ENV+=	LDFLAGS=-L${PREFIX}/lib

pre-configure:
	(cd ${WRKSRC}; autoconf)

.include "../../mk/bsd.pkg.mk"
