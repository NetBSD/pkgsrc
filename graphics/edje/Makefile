# $NetBSD: Makefile,v 1.50 2024/05/29 16:32:51 adam Exp $

DISTNAME=	edje-1.7.10
PKGREVISION=	16
CATEGORIES=	graphics
MASTER_SITES=	https://download.enlightenment.org/att/releases/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://enlightenment.org/
COMMENT=	Interface Abstraction Library and Toolset

# epp binary is GPL
LICENSE=		2-clause-bsd AND gnu-gpl-v2

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS=	pkg-config

PKG_OPTIONS_VAR=	PKG_OPTIONS.edje
PKG_SUPPORTED_OPTIONS=	python

.include "../../mk/bsd.options.mk"

PLIST_VARS+=	python

.if empty(PKG_OPTIONS:Mpython)
CONFIGURE_ARGS+=	PYTHON=:
.else
PLIST.python=	yes
REPLACE_PYTHON+=	utils/inkscape2edc
.include	"../../lang/python/application.mk"
.endif

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
