# $NetBSD: Makefile,v 1.2 2002/02/06 16:58:13 jlam Exp $
#

DISTNAME=	idiff-1.0
CATEGORIES=	devel
MASTER_SITES=	http://www.darwinsys.com/freeware/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.darwinsys.com/freeware/
COMMENT=	Interactive front-end to diff(1)

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/idiff ${PREFIX}/bin/idiff

.include "../../mk/bsd.pkg.mk"
