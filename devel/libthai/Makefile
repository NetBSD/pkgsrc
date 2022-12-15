# $NetBSD: Makefile,v 1.21 2022/12/15 10:34:30 jperkin Exp $

DISTNAME=	libthai-0.1.28
CATEGORIES=	devel
MASTER_SITES=	https://linux.thai.net/pub/thailinux/software/libthai/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://linux.thai.net/projects/libthai
COMMENT=	Thai language support routines
LICENSE=	gnu-lgpl-v2.1

USE_LIBTOOL=		yes
USE_TOOLS+=		pkg-config
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--disable-doxygen-doc
PKGCONFIG_OVERRIDE+=	libthai.pc.in
TEST_TARGET=		check

.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/libdatrie/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
