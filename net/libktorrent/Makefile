# $NetBSD: Makefile,v 1.68 2022/06/28 11:35:01 wiz Exp $

DISTNAME=	libktorrent-${LIBKTORRENT_VER}
PKGREVISION=	38
CATEGORIES=	net kde
#MASTER_SITES=	http://ktorrent.pwsp.net/downloads/${KTORRENT_VER}/
EXTRACT_SUFX=	.tar.bz2


.include "../../net/libktorrent/Makefile.version"

MAINTAINER=	pkgsrc-users@NetBSD.org
#HOMEPAGE=	http://ktorrent.pwsp.net/
COMMENT=	Torrent library split from KTorrent
LICENSE=	gnu-gpl-v2

PKG_OPTIONS_VAR=		PKG_OPTIONS.libktorrent
PKG_SUPPORTED_OPTIONS=		doc
PKG_OPTIONS_LEGACY_OPTS=	docs:doc

USE_LANGUAGES=		c c++
USE_TOOLS+=		gmake msgfmt pkg-config perl
USE_CMAKE=		yes
APIDOCS=		share/doc/libktorrent-api
WRKSRC=			${WRKDIR}/libktorrent-${LIBKTORRENT_FILEVER}

BUILD_DEPENDS+=	automoc4>=0.9.87:../../devel/automoc4

.include "../../mk/bsd.options.mk"

PLIST_VARS+=	doc
.if !empty(PKG_OPTIONS:Mdoc)
BUILD_DEPENDS+=	doxygen>=1.8.2:../../devel/doxygen
BUILD_TARGET=	all docs
PLIST.doc=	yes
USE_TOOLS+=	pax
.endif

post-install:
.if !empty(PKG_OPTIONS:Mdoc)
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}${APIDOCS}
	cd ${WRKSRC}/apidocs && ${PAX} -wr * ${DESTDIR}${PREFIX}${APIDOCS}
.endif

.include "../../devel/boost-libs/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/gmp/buildlink3.mk"
.include "../../security/qca2/buildlink3.mk"
.include "../../x11/kdelibs4/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
