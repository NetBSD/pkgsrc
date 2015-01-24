# $NetBSD: Makefile,v 1.14 2015/01/24 01:01:54 obache Exp $

PKGNAME=	suse_openssl-${SUSE_VERSION}
PKGREVISION=	12
CATEGORIES=	emulators
RPMUPDPKGS+=	libopenssl1_0_0-1.0.1k-11.64.2.${SUSE_ARCH}

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Linux compatibility package for OpenSSL

EMUL_MODULES.linux=	base

.include "../../emulators/suse131_linux/Makefile.common"
.include "../../mk/bsd.pkg.mk"
