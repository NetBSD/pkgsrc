# $NetBSD: Makefile,v 1.4 2003/06/02 01:18:11 jschauma Exp $
#

DISTNAME=	multitail-2.4
CATEGORIES=	misc sysutils
MASTER_SITES=	http://www.vanheusden.com/multitail/
EXTRACT_SUFX=	.tgz

MAINTAINER=	tech-pkg@netbsd.org
HOMEPAGE=	http://www.vanheusden.com/multitail/
COMMENT=	view one or multiple files

USE_BUILDLINK2=	yes

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/multitail ${PREFIX}/bin/
	${INSTALL_MAN} ${WRKSRC}/multitail.1 ${PREFIX}/man/man1/

.include "../../devel/ncurses/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
