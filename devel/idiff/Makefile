# $NetBSD: Makefile,v 1.3 2003/06/02 01:20:43 jschauma Exp $
#

DISTNAME=	idiff-1.0
CATEGORIES=	devel
MASTER_SITES=	http://www.darwinsys.com/freeware/

MAINTAINER=	tech-pkg@netbsd.org
HOMEPAGE=	http://www.darwinsys.com/freeware/
COMMENT=	Interactive front-end to diff(1)

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/idiff ${PREFIX}/bin/idiff

.include "../../mk/bsd.pkg.mk"
