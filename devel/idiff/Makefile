# $NetBSD: Makefile,v 1.6 2006/03/04 21:29:16 jlam Exp $
#

DISTNAME=	idiff-1.0
CATEGORIES=	devel
MASTER_SITES=	http://www.darwinsys.com/freeware/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.darwinsys.com/freeware/
COMMENT=	Interactive front-end to diff(1)

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/idiff ${PREFIX}/bin/idiff

.include "../../mk/bsd.pkg.mk"
