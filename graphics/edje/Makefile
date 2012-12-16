# $NetBSD: Makefile,v 1.3 2012/12/16 01:52:16 obache Exp $
#

DISTNAME=	edje-1.1.0
PKGREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	http://download.enlightenment.org/releases/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	joerg@NetBSD.org
HOMEPAGE=	http://enlightenment.org/
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
.include "../../lang/embryo/buildlink3.mk"
.include "../../lang/lua/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
