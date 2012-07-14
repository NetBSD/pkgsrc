# $NetBSD: Makefile,v 1.12 2012/07/14 23:42:12 wiz Exp $
#

DISTNAME=	libpciaccess-0.13.1
CATEGORIES=	sysutils x11
MASTER_SITES=	${MASTER_SITE_XORG:=lib/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://xorg.freedesktop.org/
COMMENT=	PCI access utility library from X.org

PKG_DESTDIR_SUPPORT=	user-destdir
###
### XXX This list is probably not exhaustive.
###
ONLY_FOR_PLATFORM=	FreeBSD-*-i386 NetBSD-*-i386 OpenBSD-*-i386
ONLY_FOR_PLATFORM+=	FreeBSD-*-x86_64 NetBSD-*-x86_64 OpenBSD-*-x86_64
ONLY_FOR_PLATFORM+=	DragonFly-*-i386 DragonFly-*-x86_64
ONLY_FOR_PLATFORM+=	Linux-*-* SunOS-*-*
ONLY_FOR_PLATFORM+=	NetBSD-*-sparc64 NetBSD-*-hppa

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config
###
### XXX When our patches make it upstream, this will no longer be
###	necessary.
###
USE_TOOLS+=	autoconf automake autoreconf

CONFIGURE_ARGS+=	--with-zlib

PKGCONFIG_OVERRIDE+=	pciaccess.pc.in

BUILD_DEPENDS+=	xorg-util-macros>=1.3:../../devel/xorg-util-macros

pre-configure:
	cd ${WRKSRC} && autoreconf -v -i -f

.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
