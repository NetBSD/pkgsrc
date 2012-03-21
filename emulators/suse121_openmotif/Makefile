# $NetBSD: Makefile,v 1.1.1.1 2012/03/21 13:40:24 obache Exp $

DISTNAME=	suse_openmotif-${SUSE_VERSION}
CATEGORIES=	emulators
RPMPKGS+=	openmotif-libs-2.3.2-8.1.3.${SUSE_ARCH}

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Linux compatibility package for OpenMotif

EMUL_MODULES.linux=	x11

.include "../../emulators/suse121_linux/Makefile.common"
.include "../../mk/bsd.pkg.mk"
