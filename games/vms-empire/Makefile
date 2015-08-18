# $NetBSD: Makefile,v 1.15 2015/08/18 07:31:09 wiz Exp $
#

DISTNAME=	vms-empire-1.7
PKGREVISION=	2
CATEGORIES=	games
MASTER_SITES=	http://www.catb.org/~esr/vms-empire/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.catb.org/~esr/vms-empire/
COMMENT=	Solitaire Empire (sometimes called "VMS Empire")

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man6

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/vms-empire ${DESTDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/vms-empire.6 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man6/vms-empire.6

.include "../../mk/curses.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
