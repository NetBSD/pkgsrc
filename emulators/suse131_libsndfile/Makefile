# $NetBSD: Makefile,v 1.7 2016/06/17 17:21:38 tsutsui Exp $

PKGNAME=	suse_libsndfile-${SUSE_VERSION}
PKGREVISION=	3
CATEGORIES=	emulators
RPMUPDPKGS+=	libFLAC8-1.3.0-2.4.1.${SUSE_ARCH}
RPMPKGS+=	libogg0-1.3.0-8.1.2.${SUSE_ARCH}
RPMUPDPKGS+=	libsndfile1-1.0.25-17.7.1.${SUSE_ARCH}
RPMPKGS+=	libspeex1-1.1.999_1.2rc1-21.1.2.${SUSE_ARCH}
RPMPKGS+=	libvorbis0-1.3.3-6.1.4.${SUSE_ARCH}
RPMPKGS+=	libvorbisenc2-1.3.3-6.1.4.${SUSE_ARCH}

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Linux compatibility package for libsndfile

EMUL_MODULES.linux=	base openssl

.include "../../emulators/suse131_linux/Makefile.common"
.include "../../mk/bsd.pkg.mk"
