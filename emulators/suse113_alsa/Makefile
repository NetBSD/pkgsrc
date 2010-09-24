# $NetBSD: Makefile,v 1.1.1.1 2010/09/24 01:27:50 chs Exp $

DISTNAME=	suse_alsa-${SUSE_VERSION}
CATEGORIES=	emulators
DISTFILES=	alsa-1.0.23-2.12.${SUSE_ARCH}.rpm		\
		libasound2-1.0.23-2.12.${SUSE_ARCH}.rpm

MAINTAINER=	tonio@NetBSD.org
COMMENT=	Linux compatibility package for ALSA

EMUL_MODULES.linux=	base

.include "../../emulators/suse113_linux/Makefile.common"
.include "../../mk/bsd.pkg.mk"
