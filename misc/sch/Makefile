# $NetBSD: Makefile,v 1.1.1.1 2001/02/24 05:08:03 itojun Exp $

DISTNAME=	sch-20010224
CATEGORIES=	misc
MASTER_SITES=	ftp://ftp.itojun.org/pub/misc/

MAINTAINER=	packages@netbsd.org
COMMENT=	curses-based schedule management tool

LICENSE=	no-commercial-use

GNU_CONFIGURE=	yes
WRKSRC=		${WRKDIR}/sch/build

# manpages are not complete, don't confuse people
do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/sch ${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
