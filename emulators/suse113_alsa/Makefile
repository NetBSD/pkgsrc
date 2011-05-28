# $NetBSD: Makefile,v 1.7 2011/05/28 13:54:33 wiz Exp $

DISTNAME=	suse_alsa-${SUSE_VERSION}
PKGREVISION=	3
CATEGORIES=	emulators
DISTFILES=	alsa-1.0.23-2.12.${SUSE_ARCH}.rpm		\
		alsa-oss-1.0.17-29.2.${SUSE_ARCH}.rpm		\
		alsa-plugins-1.0.23-1.9.${SUSE_ARCH}.rpm	\
		alsa-plugins-pulse-1.0.23-1.9.${SUSE_ARCH}.rpm	\
		alsa-utils-1.0.23-1.8.${SUSE_ARCH}.rpm		\
		libasound2-1.0.23-2.12.${SUSE_ARCH}.rpm

MAINTAINER=	chs@NetBSD.org
COMMENT=	Linux compatibility package for ALSA

EMUL_MODULES.linux=	base

PLIST_SRC=	${PKGDIR}/PLIST ${RPM2PKG_PLIST}

post-install:
	ln -sf asound-pulse.conf \
		${DESTDIR}${PREFIX}/${EMULSUBDIR}/etc/asound.conf

.include "../../emulators/suse113_linux/Makefile.common"
.include "../../mk/bsd.pkg.mk"
