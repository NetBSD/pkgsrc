# $NetBSD: Makefile,v 1.10 2007/01/07 09:13:55 rillig Exp $
#

DISTNAME=	vms-empire-1.7
CATEGORIES=	games
MASTER_SITES=	http://www.catb.org/~esr/vms-empire/

MAINTAINER=	pancake@phreaker.net
HOMEPAGE=	http://www.catb.org/~esr/vms-empire/
COMMENT=	Solitaire Empire (sometimes called "VMS Empire")

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man6

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/vms-empire ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/vms-empire.6 ${PREFIX}/${PKGMANDIR}/man6/vms-empire.6

.include "../../devel/ncurses/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
