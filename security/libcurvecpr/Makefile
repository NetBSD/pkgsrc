# $NetBSD: Makefile,v 1.1.1.1 2013/08/07 04:54:06 agc Exp $

DISTNAME=	master
PKGNAME=	libcurvecpr-20130806
CATEGORIES=	security
MASTER_SITES=	https://github.com/impl/libcurvecpr/archive/
EXTRACT_SUFX=	.zip

MAINTAINER=	agc@NetBSD.org
HOMEPAGE=	http://cr.yp.to/ecdh.html
COMMENT=	Uses elliptic-curve cryptography to encrypt and authenticate data
LICENSE=	modified-bsd

DIST_SUBDIR=	${PKGNAME_NOREV}

WRKSRC=		${WRKDIR}/libcurvecpr-master

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config automake autoreconf

AUTO_MKDIRS=	yes

pre-configure:
	cd ${WRKSRC} && ./autogen.sh

.include "../../security/libsodium/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
