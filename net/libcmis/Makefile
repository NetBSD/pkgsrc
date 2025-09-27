# $NetBSD: Makefile,v 1.57 2025/09/27 09:57:32 wiz Exp $

DISTNAME=	libcmis-0.6.2
PKGREVISION=	4
CATEGORIES=	net devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=tdf/}
GITHUB_PROJECT=	libcmis
GITHUB_RELEASE=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/tdf/libcmis
COMMENT=	Client library for the CMIS interface
LICENSE=	gnu-gpl-v2 OR gnu-lgpl-v2 OR mpl-1.1

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--with-man=no --disable-werror
CONFIGURE_ARGS+=	--with-boost=${BUILDLINK_DIR.boost-libs}
USE_LANGUAGES+=		c c++
USE_TOOLS+=		gmake pkg-config
USE_LIBTOOL=		yes

.include "../../devel/boost-headers/buildlink3.mk"
.include "../../devel/boost-libs/buildlink3.mk"
.include "../../devel/cppunit/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
