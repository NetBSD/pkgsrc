# $NetBSD: Makefile,v 1.2 2003/03/29 12:41:52 jmmv Exp $

DISTNAME=	sch-20010224
WRKSRC=		${WRKDIR}/sch/build
CATEGORIES=	misc
MASTER_SITES=	ftp://ftp.itojun.org/pub/misc/

MAINTAINER=	packages@netbsd.org
COMMENT=	curses-based schedule management tool

LICENSE=	no-commercial-use

GNU_CONFIGURE=	yes

# manpages are not complete, don't confuse people
do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/sch ${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
