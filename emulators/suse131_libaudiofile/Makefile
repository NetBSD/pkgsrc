# $NetBSD: Makefile,v 1.1 2014/04/17 00:08:34 wiz Exp $

DISTNAME=	suse_libaudiofile-${SUSE_VERSION}
CATEGORIES=	emulators
RPMPKGS+=	libaudiofile1-0.3.6-2.1.2.${SUSE_ARCH}

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Linux compatibility package for libaudiofile

# libsndfile is not a real dependency, but the package provides libFLAC and libogg
EMUL_MODULES.linux=	base libsndfile

.include "../../emulators/suse131_linux/Makefile.common"
.include "../../mk/bsd.pkg.mk"
