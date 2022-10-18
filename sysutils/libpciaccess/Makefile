# $NetBSD: Makefile,v 1.33 2022/10/18 07:44:03 wiz Exp $

DISTNAME=	libpciaccess-0.17
CATEGORIES=	sysutils x11
MASTER_SITES=	${MASTER_SITE_XORG:=lib/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://xorg.freedesktop.org/
COMMENT=	PCI access utility library from X.org
LICENSE=	mit AND x11

DEPENDS+=	pciids-[0-9]*:../../misc/pciids

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--with-zlib
CONFIGURE_ARGS+=	--with-pciids-path=${PREFIX}/share/pciids
USE_LIBTOOL=		yes
USE_TOOLS+=		pkg-config

PKGCONFIG_OVERRIDE+=	pciaccess.pc.in

.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
