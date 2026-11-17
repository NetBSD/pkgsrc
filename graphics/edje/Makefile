# $NetBSD: Makefile,v 1.63 2026/11/17 12:04:13 wiz Exp $

DISTNAME=	edje-1.7.10
PKGREVISION=	28
CATEGORIES=	graphics
MASTER_SITES=	https://download.enlightenment.org/att/releases/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://enlightenment.org/
COMMENT=	Interface Abstraction Library and Toolset
# epp binary is GPL
LICENSE=	2-clause-bsd AND gnu-gpl-v2

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS=	pkg-config

# edje_lua2.c:3923:16: error: too few arguments to function 'lua_newstate'
LUA_VERSIONS_INCOMPATIBLE=	55

.include "options.mk"

INSTALLATION_DIRS+=	share/doc/edje

post-install:
	${INSTALL_DATA} ${WRKSRC}/AUTHORS ${WRKSRC}/COPYING \
	    ${DESTDIR}${PREFIX}/share/doc/edje

.include "../../devel/ecore/buildlink3.mk"
.include "../../devel/eet/buildlink3.mk"
.include "../../graphics/evas/buildlink3.mk"
.include "../../graphics/evas-png/buildlink3.mk"
.include "../../graphics/evas-buffer/buildlink3.mk"
.include "../../lang/embryo/buildlink3.mk"
.include "../../lang/lua/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
