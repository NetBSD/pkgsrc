# $NetBSD: Makefile,v 1.2 2010/12/03 00:19:18 wiz Exp $

DISTNAME=	suse_alsa-${SUSE_VERSION}
PKGREVISION=	1
CATEGORIES=	emulators
DISTFILES=	alsa-1.0.23-2.12.${SUSE_ARCH}.rpm		\
		alsa-oss-1.0.17-29.2.${SUSE_ARCH}.rpm		\
		alsa-plugins-1.0.23-1.9.${SUSE_ARCH}.rpm	\
		alsa-plugins-pulse-1.0.23-1.9.${SUSE_ARCH}.rpm	\
		alsa-utils-1.0.23-1.8.${SUSE_ARCH}.rpm		\
		libasound2-1.0.23-2.12.${SUSE_ARCH}.rpm

MAINTAINER=	tonio@NetBSD.org
COMMENT=	Linux compatibility package for ALSA

EMUL_MODULES.linux=	base

.include "../../emulators/suse113_linux/Makefile.common"
.include "../../mk/bsd.pkg.mk"
