# $NetBSD: Makefile,v 1.43 2024/05/16 06:15:33 wiz Exp $

DISTNAME=	efreet-1.7.10
PKGREVISION=	13
CATEGORIES=	sysutils devel
MASTER_SITES=	https://download.enlightenment.org/att/releases/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://enlightenment.org/
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
