# $NetBSD: Makefile,v 1.18 2013/12/21 11:05:23 jperkin Exp $

DISTNAME=	libpciaccess-0.13.2
CATEGORIES=	sysutils x11
MASTER_SITES=	${MASTER_SITE_XORG:=lib/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://xorg.freedesktop.org/
COMMENT=	PCI access utility library from X.org
LICENSE=	mit AND x11

###
### XXX This list is probably not exhaustive.
###
ONLY_FOR_PLATFORM=	FreeBSD-*-i386 NetBSD-*-i386 OpenBSD-*-i386
ONLY_FOR_PLATFORM+=	FreeBSD-*-x86_64 NetBSD-*-x86_64 OpenBSD-*-x86_64
ONLY_FOR_PLATFORM+=	DragonFly-*-i386 DragonFly-*-x86_64
ONLY_FOR_PLATFORM+=	Linux-*-* SunOS-*-* Darwin-*-*
ONLY_FOR_PLATFORM+=	NetBSD-*-sparc64 NetBSD-*-hppa

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--with-zlib
USE_LIBTOOL=		yes
USE_TOOLS+=		pkg-config

PKGCONFIG_OVERRIDE+=	pciaccess.pc.in

.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
