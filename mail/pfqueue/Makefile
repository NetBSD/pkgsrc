# $NetBSD: Makefile,v 1.6 2007/01/07 09:13:59 rillig Exp $
#

DISTNAME=	pfqueue-0.1.4
CATEGORIES=	mail
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=pfqueue/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://pfqueue.sourceforge.net/
COMMENT=	Real-time queue scanner for postfix

GNU_CONFIGURE=	yes
INCOMPAT_CURSES=	NetBSD-1.*-*

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/pfqueue ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/pfqueue.1 ${PREFIX}/${PKGMANDIR}/man1

.include "../../devel/ncurses/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
