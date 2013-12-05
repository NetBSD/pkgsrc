# $NetBSD: Makefile,v 1.1 2013/12/05 11:42:15 obache Exp $

DISTNAME=	suse_libjpeg-${SUSE_VERSION}
CATEGORIES=	emulators
RPMPKGS+=	libjpeg62-62.0.0-24.1.3.${SUSE_ARCH}
RPMPKGS+=	libjpeg8-8.0.2-24.1.3.${SUSE_ARCH}

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Linux compatibility package for JPEG

EMUL_MODULES.linux=	base

.include "../../emulators/suse131_linux/Makefile.common"
.include "../../mk/bsd.pkg.mk"
