# $NetBSD: Makefile,v 1.18 2016/06/17 17:21:39 tsutsui Exp $

PKGNAME=	suse_openssl-${SUSE_VERSION}
PKGREVISION=	14
CATEGORIES=	emulators
RPMUPDPKGS+=	libopenssl1_0_0-1.0.1k-11.87.1.${SUSE_ARCH}

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Linux compatibility package for OpenSSL

EMUL_MODULES.linux=	base

.include "../../emulators/suse131_linux/Makefile.common"
.include "../../mk/bsd.pkg.mk"
