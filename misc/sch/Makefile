# $NetBSD: Makefile,v 1.8 2006/03/04 21:30:13 jlam Exp $

DISTNAME=	sch-20010224
CATEGORIES=	misc
MASTER_SITES=	ftp://ftp.itojun.org/pub/misc/

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Curses-based schedule management tool

LICENSE=	no-commercial-use

WRKSRC=		${WRKDIR}/sch/build
GNU_CONFIGURE=	yes

INSTALLATION_DIRS=	bin

# manpages are not complete, don't confuse people
do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/sch ${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
