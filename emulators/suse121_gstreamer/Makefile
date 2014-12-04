# $NetBSD: Makefile,v 1.1 2014/12/04 19:51:42 rodent Exp $

PKGNAME=	suse_gstreamer-${SUSE_VERSION}
CATEGORIES=	emulators
RPMPKGS+=	libgstapp-0_10-0-0.10.35-6.1.2.${SUSE_ARCH}
RPMPKGS+=	libgstbasevideo-0_10-0-0.10.22-8.1.2.${SUSE_ARCH}
RPMPKGS+=	libgstinterfaces-0_10-0-0.10.35-6.1.2.${SUSE_ARCH} 
RPMPKGS+=	libgstreamer-0_10-0-0.10.35-4.1.4.${SUSE_ARCH}
RPMPKGS+=	libgstrtspserver-0_10-0-0.10.8-14.1.2.${SUSE_ARCH}

MAINTAINER=	rodent@NetBSD.org
COMMENT=	Linux compatibility package for gstreamer

PLIST_SRC=	${RPM2PKG_PLIST}

.include "../../emulators/suse121_linux/Makefile.common"
.include "../../mk/bsd.pkg.mk"
