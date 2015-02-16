# $NetBSD: Makefile,v 1.4 2015/02/16 10:15:49 jperkin Exp $

PKGNAME=	suse_motif-${SUSE_VERSION}
CATEGORIES=	emulators
RPMPKGS+=	motif-2.3.4-2.1.3.${SUSE_ARCH}
RPMPKGS+=	libMrm4-2.3.4-2.1.3.${SUSE_ARCH}
RPMPKGS+=	libUil4-2.3.4-2.1.3.${SUSE_ARCH}
RPMPKGS+=	libXm4-2.3.4-2.1.3.${SUSE_ARCH}

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Linux compatibility package for Motif

EMUL_MODULES.linux=	x11

.include "../../emulators/suse131_linux/Makefile.common"
.include "../../mk/bsd.pkg.mk"
