# $NetBSD: Makefile,v 1.21 2012/09/15 10:06:19 obache Exp $

DISTNAME=	qca-ossl-2.0.0-beta3
PKGNAME=	qca2-ossl-${DISTNAME:S/-beta/beta/:C/.*-//}
PKGREVISION=	18
CATEGORIES=	security
MASTER_SITES=	http://delta.affinix.com/download/qca/2.0/plugins/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://delta.affinix.com/qca/
COMMENT=	Cross-platform crypto API for QT - OpenSSL plugin

PKG_DESTDIR_SUPPORT=	user-destdir

USE_TOOLS+=	gmake
USE_LIBTOOL=	yes
HAS_CONFIGURE=	yes
USE_LANGUAGES=	c c++

CONFIGURE_ARGS+=	--qtdir=${QTDIR}
CONFIGURE_ARGS+=	--with-qca=${QTDIR}
CONFIGURE_ARGS+=	--with-openssl-inc=${SSLBASE}/include
CONFIGURE_ARGS+=	--with-openssl-lib=${SSLBASE}/lib

INSTALL_MAKE_FLAGS+=	INSTALL_ROOT=${DESTDIR}

.include "../../security/qca2/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
