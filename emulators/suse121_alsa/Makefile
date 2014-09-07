# $NetBSD: Makefile,v 1.2 2014/09/07 12:26:40 obache Exp $

PKGNAME=	suse_alsa-${SUSE_VERSION}
CATEGORIES=	emulators
RPMPKGS+=	alsa-1.0.24.1-23.1.2.${SUSE_ARCH}
RPMPKGS+=	alsa-oss-1.0.17-37.1.2.${SUSE_ARCH}
RPMPKGS+=	alsa-plugins-1.0.24-18.1.2.${SUSE_ARCH}
RPMPKGS+=	alsa-plugins-pulse-1.0.24-18.1.2.${SUSE_ARCH}
RPMPKGS+=	alsa-utils-1.0.24.2-12.8.1.${SUSE_ARCH}
RPMPKGS+=	libasound2-1.0.24.1-23.1.2.${SUSE_ARCH}

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Linux compatibility package for ALSA

EMUL_MODULES.linux=	base

PLIST_SRC=	${PKGDIR}/PLIST ${RPM2PKG_PLIST}

post-install:
	ln -sf asound-pulse.conf \
		${DESTDIR}${PREFIX}/${EMULSUBDIR}/etc/asound.conf

.include "../../emulators/suse121_linux/Makefile.common"
.include "../../mk/bsd.pkg.mk"
