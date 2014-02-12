# $NetBSD: Makefile,v 1.43 2014/02/12 23:18:36 tron Exp $

DISTNAME=	qca-tls-1.0
PKGREVISION=	18
CATEGORIES=	security
MASTER_SITES=	http://delta.affinix.com/download/qca/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://delta.affinix.com/qca/
COMMENT=	Cross-platform crypto API for QT - TLS plugin

USE_TOOLS+=	gmake
USE_LIBTOOL=	yes
HAS_CONFIGURE=	yes
USE_LANGUAGES=	c c++

CONFIGURE_ARGS+=	--with-openssl-inc=${SSLBASE}/include
CONFIGURE_ARGS+=	--with-openssl-lib=${SSLBASE}/lib

INSTALL_MAKE_FLAGS+=	INSTALL_ROOT=${DESTDIR:Q}

SUBST_CLASSES+=		rpath
SUBST_STAGE.rpath=	pre-configure
SUBST_MESSAGE.rpath=	Substituting compiler RPATH flag.
SUBST_FILES.rpath=	configure
SUBST_VARS.rpath=	COMPILER_RPATH_FLAG

pre-install:
	mkdir -p ${DESTDIR}${PREFIX}/qt3/plugins/crypto

.include "../../security/openssl/buildlink3.mk"
.include "../../x11/qt3-libs/buildlink3.mk"
BUILDLINK_API_DEPENDS.qt3-tools+=	qt3-tools>=3.3.5nb6
.include "../../x11/qt3-tools/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
