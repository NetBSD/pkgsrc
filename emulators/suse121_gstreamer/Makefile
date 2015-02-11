# $NetBSD: Makefile,v 1.3 2015/02/11 09:38:15 obache Exp $

DISTNAME=	suse_gstreamer-${SUSE_VERSION}
CATEGORIES=	emulators
RPMPKGS+=	libgstapp-0_10-0-0.10.35-6.1.2.${SUSE_ARCH}
RPMPKGS+=	libgstbasevideo-0_10-0-0.10.22-8.1.2.${SUSE_ARCH}
RPMPKGS+=	libgstinterfaces-0_10-0-0.10.35-6.1.2.${SUSE_ARCH} 
RPMPKGS+=	libgstreamer-0_10-0-0.10.35-4.1.4.${SUSE_ARCH}
RPMPKGS+=	libgstrtspserver-0_10-0-0.10.8-14.1.2.${SUSE_ARCH}

MAINTAINER=	rodent@NetBSD.org
COMMENT=	Linux compatibility package for gstreamer

EMUL_MODULES.linux=	base

PLIST_SRC=	${RPM2PKG_PLIST}

.include "../../emulators/suse121_linux/Makefile.common"
.include "../../mk/bsd.pkg.mk"
