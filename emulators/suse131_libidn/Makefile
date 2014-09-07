# $NetBSD: Makefile,v 1.2 2014/09/07 12:26:43 obache Exp $

PKGNAME=	suse_libidn-${SUSE_VERSION}
CATEGORIES=	emulators
RPMPKGS+=	libidn11-1.25-7.1.2.${SUSE_ARCH}

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Linux compatibility package for libidn

EMUL_MODULES.linux=	base

.include "../../emulators/suse131_linux/Makefile.common"
.include "../../mk/bsd.pkg.mk"
