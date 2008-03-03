# $NetBSD: Makefile,v 1.7 2008/03/03 17:45:35 jlam Exp $
#

DISTNAME=	idiff-1.0
CATEGORIES=	devel
MASTER_SITES=	http://www.darwinsys.com/freeware/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.darwinsys.com/freeware/
COMMENT=	Interactive front-end to diff(1)

PKG_DESTDIR_SUPPORT=	user-destdir

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/idiff ${DESTDIR}${PREFIX}/bin/idiff

.include "../../mk/bsd.pkg.mk"
