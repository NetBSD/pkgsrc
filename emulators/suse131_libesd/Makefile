# $NetBSD: Makefile,v 1.4 2015/02/16 10:15:48 jperkin Exp $

PKGNAME=	suse_libesd-${SUSE_VERSION}
CATEGORIES=	emulators
RPMPKGS+=	libesd0-0.2.41-26.1.2.${SUSE_ARCH}

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Linux compatibility package for esd/esound

EMUL_MODULES.linux=	base alsa libaudiofile

.include "../../emulators/suse131_linux/Makefile.common"
.include "../../mk/bsd.pkg.mk"
