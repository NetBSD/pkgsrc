# $NetBSD: Makefile,v 1.11 2007/11/29 20:52:07 heinz Exp $
#

DISTNAME=	vms-empire-1.7
CATEGORIES=	games
MASTER_SITES=	http://www.catb.org/~esr/vms-empire/

MAINTAINER=	pancake@phreaker.net
HOMEPAGE=	http://www.catb.org/~esr/vms-empire/
COMMENT=	Solitaire Empire (sometimes called "VMS Empire")

PKG_DESTDIR_SUPPORT=	user-destdir

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man6

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/vms-empire ${DESTDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/vms-empire.6 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man6/vms-empire.6

.include "../../devel/ncurses/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
