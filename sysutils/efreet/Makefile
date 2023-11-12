# $NetBSD: Makefile,v 1.42 2023/11/12 13:23:31 wiz Exp $

DISTNAME=	efreet-1.7.10
PKGREVISION=	12
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
