# $NetBSD: Makefile,v 1.5 2006/03/04 21:30:01 jlam Exp $
#

DISTNAME=	pfqueue-0.1.4
CATEGORIES=	mail
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=pfqueue/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://pfqueue.sourceforge.net/
COMMENT=	Real-time queue scanner for postfix

GNU_CONFIGURE=	yes
INCOMPAT_CURSES=	NetBSD-1.*-*

INSTALLATION_DIRS=	bin man/man1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/pfqueue ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/pfqueue.1 ${PREFIX}/man/man1

.include "../../devel/ncurses/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
