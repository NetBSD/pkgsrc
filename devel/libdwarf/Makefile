# $NetBSD: Makefile,v 1.3 2022/03/19 08:47:25 wiz Exp $

DISTNAME=	libdwarf-0.3.4
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
