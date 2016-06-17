# $NetBSD: Makefile,v 1.9 2016/06/17 17:21:38 tsutsui Exp $

PKGNAME=	suse_libxml2-${SUSE_VERSION}
PKGREVISION=	3
CATEGORIES=	emulators
RPMUPDPKGS+=	libxml2-2-2.9.3-2.19.1.${SUSE_ARCH}

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Linux compatibility package for libxml2

EMUL_MODULES.linux=	base

.include "../../emulators/suse131_linux/Makefile.common"
.include "../../mk/bsd.pkg.mk"
