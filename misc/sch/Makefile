# $NetBSD: Makefile,v 1.6 2004/01/20 12:21:02 agc Exp $

DISTNAME=	sch-20010224
CATEGORIES=	misc
MASTER_SITES=	ftp://ftp.itojun.org/pub/misc/

MAINTAINER=	tech-pkg@NetBSD.org
COMMENT=	Curses-based schedule management tool

LICENSE=	no-commercial-use

WRKSRC=		${WRKDIR}/sch/build
GNU_CONFIGURE=	yes

# manpages are not complete, don't confuse people
do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/sch ${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
