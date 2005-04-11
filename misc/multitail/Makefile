# $NetBSD: Makefile,v 1.12 2005/04/11 21:46:38 tv Exp $
#

DISTNAME=	multitail-2.4
PKGREVISION=	2
CATEGORIES=	misc sysutils
MASTER_SITES=	http://www.vanheusden.com/multitail/
EXTRACT_SUFX=	.tgz

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.vanheusden.com/multitail/
COMMENT=	View one or multiple files


do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/multitail ${PREFIX}/bin/
	${INSTALL_MAN} ${WRKSRC}/multitail.1 ${PREFIX}/man/man1/

.include "../../devel/ncurses/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
