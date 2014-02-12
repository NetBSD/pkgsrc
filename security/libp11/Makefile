# $NetBSD: Makefile,v 1.9 2014/02/12 23:18:33 tron Exp $
#

DISTNAME=		libp11-0.2.6
PKGREVISION=		4
CATEGORIES=		security
MASTER_SITES=		http://www.opensc-project.org/files/libp11/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.opensc-project.org/libp11/
COMMENT=		Convenience library for easy PKCS\#11 implementation
LICENSE=		gnu-lgpl-v2.1

BUILDLINK_API_DEPENDS.openssl+=	openssl>=0.9.7

USE_PKGLOCALEDIR=	yes
USE_LIBTOOL=		yes
PKGCONFIG_OVERRIDE+=	${WRKSRC}/src/libp11.pc.in
GNU_CONFIGURE=		yes
USE_TOOLS+=		gmake pkg-config

.include "../../devel/libltdl/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
