# $NetBSD: Makefile,v 1.2 2002/10/03 08:42:41 cjep Exp $
#

DISTNAME=	ee-1.4.5a.src
PKGNAME=	easyedit-1.4.5a
CATEGORIES=	editors
MASTER_SITES=	http://mahon.cwx.net/sources/
EXTRACT_SUFX=	.tgz

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://mahon.cwx.net/
COMMENT=	Easy to use text editor

WRKSRC=		${WRKDIR}/${PKGNAME}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/ee ${PREFIX}/bin/easyedit
	${INSTALL_MAN} ${WRKSRC}/ee.1 ${PREFIX}/man/man1/easyedit.1

.include "../../mk/bsd.pkg.mk"
