# $NetBSD: Makefile,v 1.3 2015/01/15 09:33:55 obache Exp $

PKGNAME=	suse_libsndfile-${SUSE_VERSION}
PKGREVISION=	1
CATEGORIES=	emulators
RPMUPDPKGS+=	libsndfile1-1.0.25-17.4.1.${SUSE_ARCH}
RPMPKGS+=	libFLAC8-1.3.0-2.1.2.${SUSE_ARCH}
RPMPKGS+=	libvorbis0-1.3.3-6.1.4.${SUSE_ARCH}
RPMPKGS+=	libvorbisenc2-1.3.3-6.1.4.${SUSE_ARCH}
RPMPKGS+=	libspeex1-1.1.999_1.2rc1-21.1.2.${SUSE_ARCH}
RPMPKGS+=	libogg0-1.3.0-8.1.2.${SUSE_ARCH}

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Linux compatibility package for libsndfile

EMUL_MODULES.linux=	base openssl

.include "../../emulators/suse131_linux/Makefile.common"
.include "../../mk/bsd.pkg.mk"
