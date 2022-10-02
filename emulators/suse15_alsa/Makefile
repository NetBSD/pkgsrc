# $NetBSD: Makefile,v 1.1 2022/10/02 17:17:17 wiz Exp $

PKGNAME=	suse_alsa-${SUSE_VERSION}
CATEGORIES=	emulators
RPMPKGS+=	alsa-1.2.6.1-150400.1.4.${SUSE_ARCH}
RPMPKGS+=	alsa-oss-1.1.8-150300.12.3.2.${SUSE_ARCH}
RPMPKGS+=	alsa-plugins-1.2.6-150400.1.10.${SUSE_ARCH}
RPMPKGS+=	alsa-plugins-pulse-1.2.6-150400.1.10.${SUSE_ARCH}
RPMPKGS+=	alsa-utils-1.2.6-150400.1.4.${SUSE_ARCH}
RPMPKGS+=	libasound2-1.2.6.1-150400.1.4.${SUSE_ARCH}
RPMPKGS+=	libatopology2-1.2.6.1-150400.1.4.${SUSE_ARCH}
RPMPKGS+=	libsamplerate0-0.1.9-3.22.${SUSE_ARCH}

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Linux compatibility package for ALSA

EMUL_MODULES.linux=	base pulseaudio

PLIST_SRC=	${PKGDIR}/PLIST ${RPM2PKG_PLIST}

post-install:
	${INSTALL_DATA} ${FILESDIR}/60-oss.conf \
		${DESTDIR}${PREFIX}/${EMULSUBDIR}/usr/share/alsa/alsa.conf.d/
# TODO: needs checking
	${SED} -e 's/type pulse/type oss/g' \
		< ${DESTDIR}${PREFIX}/${EMULSUBDIR}/etc/alsa/conf.d/99-pulseaudio-default.conf.example \
		> ${DESTDIR}${PREFIX}/${EMULSUBDIR}/etc/alsa/conf.d/99-oss-default.conf

.include "../../emulators/suse15_linux/Makefile.common"
.include "../../mk/bsd.pkg.mk"
