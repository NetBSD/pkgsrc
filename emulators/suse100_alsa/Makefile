# $NetBSD: Makefile,v 1.2 2014/09/07 12:26:39 obache Exp $

PKGNAME=	suse_alsa-${SUSE_VERSION}
CATEGORIES=	emulators
DISTFILES=	alsa-1.0.9-23.2.${SUSE_ARCH}.rpm

MAINTAINER=	tonio@NetBSD.org
COMMENT=	Linux compatibility package for ALSA

EMUL_MODULES.linux=	base

.include "../../emulators/suse100_linux/Makefile.common"
.include "../../mk/bsd.pkg.mk"
