# $NetBSD: Makefile,v 1.15 2006/03/13 21:56:22 minskim Exp $

DISTNAME=	qca-tls-1.0
PKGREVISION=	2
CATEGORIES=	security
MASTER_SITES=	http://delta.affinix.com/download/qca/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	jdolecek@NetBSD.org
HOMEPAGE=	http://delta.affinix.com/qca/
COMMENT=	Cross-platform crypto API for QT - TLS plugin

USE_TOOLS+=	gmake
USE_LIBTOOL=	yes
HAS_CONFIGURE=	yes

CONFIGURE_ARGS+=        --with-openssl-inc=${SSLBASE}/include
CONFIGURE_ARGS+=        --with-openssl-lib=${SSLBASE}/lib

.include "../../security/openssl/buildlink3.mk"
.include "../../x11/qt3-libs/buildlink3.mk"
BUILDLINK_DEPENDS.qt3-tools+=	qt3-tools>=3.3.5nb6
.include "../../x11/qt3-tools/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
