# $NetBSD: Makefile,v 1.1 2022/10/02 17:17:19 wiz Exp $

PKGNAME=	suse_libsndfile-${SUSE_VERSION}
CATEGORIES=	emulators
RPMPKGS+=	libFLAC8-1.3.2-150000.3.11.1.${SUSE_ARCH}
RPMPKGS+=	libogg0-1.3.2-150000.3.2.1.${SUSE_ARCH}
RPMPKGS+=	libsndfile1-1.0.28-150000.5.17.1.${SUSE_ARCH}
RPMPKGS+=	libspeex1-1.2-150000.3.5.2.${SUSE_ARCH}
RPMPKGS+=	libvorbis0-1.3.6-150000.4.5.2.${SUSE_ARCH}
RPMPKGS+=	libvorbisenc2-1.3.6-150000.4.5.2.${SUSE_ARCH}

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Linux compatibility package for libsndfile

EMUL_MODULES.linux=	base openssl

.include "../../emulators/suse15_linux/Makefile.common"
.include "../../mk/bsd.pkg.mk"
