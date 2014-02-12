# $NetBSD: Makefile,v 1.9 2014/02/12 23:18:38 tron Exp $
#

DISTNAME=	efreet-1.7.7
PKGREVISION=	1
CATEGORIES=	sysutils devel
MASTER_SITES=	http://download.enlightenment.org/releases/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	joerg@NetBSD.org
HOMEPAGE=	http://enlightenment.org/
COMMENT=	Interface Abstraction Library and Toolset
LICENSE=	2-clause-bsd

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS=	pkg-config

INSTALLATION_DIRS=	share/doc/efreet

post-install:
	${INSTALL_DATA} ${WRKSRC}/AUTHORS ${WRKSRC}/COPYING \
	    ${DESTDIR}${PREFIX}/share/doc/efreet

.include "../../devel/ecore/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
