# $NetBSD: Makefile,v 1.7 2022/08/05 07:54:39 adam Exp $

DISTNAME=	libaacs-0.11.1
CATEGORIES=	multimedia
MASTER_SITES=	http://download.videolan.org/pub/videolan/libaacs/${PKGVERSION_NOREV}/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.videolan.org/developers/libaacs.html
COMMENT=	Advanced Access Content System specification implementation
LICENSE=	gnu-lgpl-v2.1

USE_LIBTOOL=		yes
USE_TOOLS+=		flex bison pkg-config
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--disable-optimizations
PKGCONFIG_OVERRIDE+=	src/libaacs.pc.in

.include "../../security/libgcrypt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
