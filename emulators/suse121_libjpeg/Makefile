# $NetBSD: Makefile,v 1.1.1.1 2012/03/21 13:38:03 obache Exp $

DISTNAME=	suse_libjpeg-${SUSE_VERSION}
CATEGORIES=	emulators
RPMPKGS+=	libjpeg62-62.0.0-10.1.2.${SUSE_ARCH}
RPMPKGS+=	libjpeg8-8.0.2-8.1.2.${SUSE_ARCH}

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Linux compatibility package for JPEG

EMUL_MODULES.linux=	base

.include "../../emulators/suse121_linux/Makefile.common"
.include "../../mk/bsd.pkg.mk"
