# $NetBSD: Makefile,v 1.8 2003/09/27 17:07:37 grant Exp $
#

DISTNAME=	multitail-2.4
PKGREVISION=	1
CATEGORIES=	misc sysutils
MASTER_SITES=	http://www.vanheusden.com/multitail/
EXTRACT_SUFX=	.tgz

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.vanheusden.com/multitail/
COMMENT=	View one or multiple files

USE_BUILDLINK2=	yes

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/multitail ${PREFIX}/bin/
	${INSTALL_MAN} ${WRKSRC}/multitail.1 ${PREFIX}/man/man1/

.include "../../mk/curses.buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
