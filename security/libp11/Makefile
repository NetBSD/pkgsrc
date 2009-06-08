# $NetBSD: Makefile,v 1.2 2009/06/08 19:11:30 hasso Exp $
#

DISTNAME=		libp11-0.2.4
CATEGORIES=		security
MASTER_SITES=		http://www.opensc-project.org/files/libp11/

MAINTAINER=		hasso@NetBSD.org
HOMEPAGE=		http://www.opensc-project.org/libp11/
COMMENT=		Convenience library for easy PKCS\#11 implementation
LICENSE=		gnu-lgpl-v2.1

PKG_DESTDIR_SUPPORT=	user-destdir

BUILDLINK_API_DEPENDS.openssl+=	openssl>=0.9.7

USE_PKGLOCALEDIR=	yes
USE_LIBTOOL=		yes
PKGCONFIG_OVERRIDE+=	${WRKSRC}/src/libp11.pc.in
GNU_CONFIGURE=		yes
USE_TOOLS+=		gmake pkg-config

.include "../../devel/libltdl/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
