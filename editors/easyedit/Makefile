# $NetBSD: Makefile,v 1.4 2003/06/02 01:20:11 jschauma Exp $
#

DISTNAME=	ee-1.4.5a.src
PKGNAME=	easyedit-1.4.5a
WRKSRC=		${WRKDIR}/${PKGNAME}
CATEGORIES=	editors
MASTER_SITES=	http://mahon.cwx.net/sources/
EXTRACT_SUFX=	.tgz

MAINTAINER=	tech-pkg@netbsd.org
HOMEPAGE=	http://mahon.cwx.net/
COMMENT=	Easy to use text editor

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/ee ${PREFIX}/bin/easyedit
	${INSTALL_MAN} ${WRKSRC}/ee.1 ${PREFIX}/man/man1/easyedit.1

.include "../../mk/bsd.pkg.mk"
