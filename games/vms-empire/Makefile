# $NetBSD: Makefile,v 1.1.1.1 2003/06/02 14:09:48 jmmv Exp $
#

DISTNAME=	vms-empire-1.4
CATEGORIES=	games
MASTER_SITES=	http://www.catb.org/~esr/vms-empire/

MAINTAINER=	pancake@phreaker.net
HOMEPAGE=	http://www.catb.org/~esr/vms-empire/
COMMENT=	Solitaire Empire (sometimes called "VMS Empire")

USE_BUILDLINK2=	yes

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/vms-empire ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/vms-empire.6 ${PREFIX}/man/man6/vms-empire.6

.include "../../devel/ncurses/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
