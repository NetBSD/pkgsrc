# $NetBSD: Makefile,v 1.10 2013/04/26 05:15:57 wiz Exp $
#

DISTNAME=		libfontenc-1.1.2
CATEGORIES=		x11
MASTER_SITES=		${MASTER_SITE_XORG:=lib/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		joerg@NetBSD.org
HOMEPAGE=		http://xorg.freedesktop.org/
COMMENT=		The fontenc Library from X.org

USE_LIBTOOL=		yes
USE_TOOLS+=		pkg-config
PKGCONFIG_OVERRIDE+=	fontenc.pc.in
GNU_CONFIGURE=		yes

.include "../../meta-pkgs/modular-xorg/hacks.mk"

.include "../../devel/zlib/buildlink3.mk"
.include "../../x11/xproto/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
