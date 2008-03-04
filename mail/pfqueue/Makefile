# $NetBSD: Makefile,v 1.7 2008/03/04 17:57:19 jlam Exp $
#

DISTNAME=	pfqueue-0.1.4
CATEGORIES=	mail
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=pfqueue/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://pfqueue.sourceforge.net/
COMMENT=	Real-time queue scanner for postfix

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes
INCOMPAT_CURSES=	NetBSD-1.*-*

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/pfqueue ${DESTDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/pfqueue.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1

.include "../../devel/ncurses/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
