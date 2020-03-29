# $NetBSD: Makefile,v 1.14 2020/03/29 02:13:32 manu Exp $
#

VERSION=		0.4.4
DISTNAME=		libp11-${VERSION}
PKGREVISION=		2
CATEGORIES=		security
MASTER_SITES=		https://github.com/OpenSC/libp11/archive/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://github.com/OpenSC/libp11/wiki
COMMENT=		Convenience library for easy PKCS\#11 implementation
LICENSE=		gnu-lgpl-v2.1

WRKSRC=			${WRKDIR}/libp11-libp11-${VERSION}

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
