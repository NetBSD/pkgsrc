# $NetBSD: Makefile,v 1.3 2015/02/16 10:15:47 jperkin Exp $

PKGNAME=	suse_gstreamer-${SUSE_VERSION}
CATEGORIES=	emulators
RPMUPDPKGS+=	gstreamer-plugin-gstclutter-2.0.8-3.1.${SUSE_ARCH}
RPMUPDPKGS+=	gstreamer-plugins-bad-1.0.10-2.5.4.${SUSE_ARCH}
RPMUPDPKGS+=	gstreamer-plugins-base-1.0.10-2.4.1.${SUSE_ARCH}

MAINTAINER=	rodent@NetBSD.org
COMMENT=	Linux compatibility package for gstreamer

EMUL_MODULES.linux=	base

PLIST_SRC=	${RPM2PKG_PLIST}

.include "../../emulators/suse131_linux/Makefile.common"
.include "../../mk/bsd.pkg.mk"
