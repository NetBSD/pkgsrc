# $NetBSD: Makefile,v 1.11 2016/03/05 11:27:54 jperkin Exp $
#

VERSION=		0.2.8
DISTNAME=		libp11-${VERSION}
PKGREVISION=		1
CATEGORIES=		security
MASTER_SITES=		https://github.com/OpenSC/libp11/archive/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://github.com/OpenSC/libp11/wiki
COMMENT=		Convenience library for easy PKCS\#11 implementation
LICENSE=		gnu-lgpl-v2.1

WRKSRC=			${WRKDIR}/libp11-libp11-${VERSION}

BUILDLINK_API_DEPENDS.openssl+=	openssl>=0.9.7

USE_TOOLS+=		autoconf automake gmake pkg-config
GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes
USE_PKGLOCALEDIR=	yes
PKGCONFIG_OVERRIDE+=	${WRKSRC}/src/libp11.pc.in

pre-configure:
	cd ${WRKSRC} && ./bootstrap

.include "../../devel/libltdl/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
