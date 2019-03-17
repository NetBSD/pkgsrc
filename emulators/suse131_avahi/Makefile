# $NetBSD: Makefile,v 1.1 2019/03/17 01:10:58 tsutsui Exp $

PKGNAME=	suse_avahi-${SUSE_VERSION}
CATEGORIES=	emulators
#RPMUPDPKGS+=	avahi-0.6.31-16.6.1.${SUSE_ARCH}
#RPMUPDPKGS+=	avahi-autoipd-0.6.31-16.6.1.${SUSE_ARCH}
#RPMUPDPKGS+=	avahi-compat-howl-devel-0.6.31-16.6.1.${SUSE_ARCH}
#RPMUPDPKGS+=	avahi-compat-mDNSResponder-devel-0.6.31-16.6.1.${SUSE_ARCH}
#RPMUPDPKGS+=	avahi-mono-0.6.31-16.6.1.${SUSE_ARCH}
RPMUPDPKGS+=	avahi-utils-0.6.31-16.6.1.${SUSE_ARCH}
#RPMUPDPKGS+=	avahi-utils-gtk-0.6.31-16.6.1.${SUSE_ARCH}
RPMUPDPKGS+=	libavahi-client3-0.6.31-16.6.1.${SUSE_ARCH}
RPMUPDPKGS+=	libavahi-common3-0.6.31-16.6.1.${SUSE_ARCH}
#RPMUPDPKGS+=	libavahi-core7-0.6.31-16.6.1.${SUSE_ARCH}
#RPMUPDPKGS+=	libavahi-glib1-0.6.31-16.6.1.${SUSE_ARCH}
#RPMUPDPKGS+=	libavahi-glib1-32bit-0.6.31-16.6.1.${SUSE_ARCH}
#RPMUPDPKGS+=	libavahi-gobject0-0.6.31-16.6.1.${SUSE_ARCH}
#RPMUPDPKGS+=	libavahi-qt4-1-0.6.31-16.6.1.${SUSE_ARCH}
#RPMUPDPKGS+=	libavahi-ui-gtk3-0-0.6.31-16.6.1.${SUSE_ARCH}
#RPMUPDPKGS+=	libavahi-ui0-0.6.31-16.6.1.${SUSE_ARCH}

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Linux compatibility package for avahi

EMUL_MODULES.linux=	base dbus

.include "../../emulators/suse131_linux/Makefile.common"
.include "../../mk/bsd.pkg.mk"
