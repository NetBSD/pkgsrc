# $NetBSD: Makefile,v 1.1.1.1 2001/03/22 10:04:36 agc Exp $
#

DISTNAME=	idiff-1.0
CATEGORIES=	devel
MASTER_SITES=	http://www.darwinsys.com/freeware/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.darwinsys.com/freeware/
COMMENT=	Interactive front-end to diff(1)

do-install:
	${BSD_INSTALL_PROGRAM} ${WRKSRC}/idiff ${PREFIX}/bin/idiff

.include "../../mk/bsd.pkg.mk"
