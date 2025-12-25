# $NetBSD: Makefile,v 1.4 2025/12/25 16:57:54 ryoon Exp $

DISTNAME=	libdwarf-2.2.0
CATEGORIES=	devel
MASTER_SITES=	https://www.prevanders.net/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.prevanders.net/dwarf.html
COMMENT=	Tools for parsing DWARF debug information
LICENSE=	gnu-lgpl-v2.1 AND gnu-gpl-v2

GNU_CONFIGURE=	yes
USE_LANGUAGES=	c c++
USE_LIBTOOL=	yes

PKGCONFIG_OVERRIDE+=	libdwarf.pc.in

CONFIGURE_ARGS+=	--enable-shared

.include "../../mk/bsd.pkg.mk"
