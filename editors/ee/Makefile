# $NetBSD: Makefile,v 1.1.1.1 2002/10/02 21:37:41 cjep Exp $
#

DISTNAME=	ee-1.4.5a.src
PKGNAME=	ee-1.4.5a
CATEGORIES=	editors
MASTER_SITES=	http://mahon.cwx.net/sources/
EXTRACT_SUFX=	.tgz

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://mahon.cwx.net/
COMMENT=	Easy to use text editor

WRKSRC=		${WRKDIR}/easyedit-1.4.5a

do-install:
	${CP} ${WRKSRC}/ee ${PREFIX}/bin/ee
	${CP} ${WRKSRC}/ee.1 ${PREFIX}/man/man1/ee.1

.include "../../mk/bsd.pkg.mk"
