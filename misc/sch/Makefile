# $NetBSD: Makefile,v 1.5 2003/07/21 17:01:27 martti Exp $

DISTNAME=	sch-20010224
WRKSRC=		${WRKDIR}/sch/build
CATEGORIES=	misc
MASTER_SITES=	ftp://ftp.itojun.org/pub/misc/

MAINTAINER=	tech-pkg@NetBSD.org
COMMENT=	Curses-based schedule management tool

LICENSE=	no-commercial-use

GNU_CONFIGURE=	yes

# manpages are not complete, don't confuse people
do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/sch ${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
