# $NetBSD: Makefile,v 1.5 2009/08/26 19:58:16 sno Exp $

DISTNAME=	qca-ossl-2.0.0-beta3
PKGNAME=	qca2-ossl-${DISTNAME:S/-beta/beta/:C/.*-//}
PKGREVISION=	4
CATEGORIES=	security
MASTER_SITES=	http://delta.affinix.com/download/qca/2.0/plugins/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	jdolecek@NetBSD.org
HOMEPAGE=	http://delta.affinix.com/qca/
COMMENT=	Cross-platform crypto API for QT - OpenSSL plugin

USE_TOOLS+=	gmake
USE_LIBTOOL=	yes
HAS_CONFIGURE=	yes
USE_LANGUAGES=	c c++

CONFIGURE_ARGS+=	--qtdir=${QTDIR}
CONFIGURE_ARGS+=	--with-qca=${QTDIR}
CONFIGURE_ARGS+=	--with-openssl-inc=${SSLBASE}/include
CONFIGURE_ARGS+=	--with-openssl-lib=${SSLBASE}/lib

.include "../../security/qca2/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
