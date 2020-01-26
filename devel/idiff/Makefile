# $NetBSD: Makefile,v 1.9 2020/01/26 17:30:58 rillig Exp $
#

DISTNAME=	idiff-1.0
CATEGORIES=	devel
MASTER_SITES=	http://www.darwinsys.com/freeware/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.darwinsys.com/freeware/
COMMENT=	Interactive front-end to diff(1)

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/idiff ${DESTDIR}${PREFIX}/bin/idiff

.include "../../mk/bsd.pkg.mk"
