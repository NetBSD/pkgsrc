# $NetBSD: Makefile,v 1.7 2004/11/04 12:15:40 wiz Exp $
#

DISTNAME=	vms-empire-1.7
CATEGORIES=	games
MASTER_SITES=	http://www.catb.org/~esr/vms-empire/

MAINTAINER=	pancake@phreaker.net
HOMEPAGE=	http://www.catb.org/~esr/vms-empire/
COMMENT=	Solitaire Empire (sometimes called "VMS Empire")

USE_BUILDLINK3=	yes

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/vms-empire ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/vms-empire.6 ${PREFIX}/man/man6/vms-empire.6

.include "../../devel/ncurses/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
