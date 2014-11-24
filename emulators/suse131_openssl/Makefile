# $NetBSD: Makefile,v 1.13 2014/11/24 10:47:45 obache Exp $

PKGNAME=	suse_openssl-${SUSE_VERSION}
PKGREVISION=	11
CATEGORIES=	emulators
RPMUPDPKGS+=	libopenssl1_0_0-1.0.1j-11.59.1.${SUSE_ARCH}

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Linux compatibility package for OpenSSL

EMUL_MODULES.linux=	base

.include "../../emulators/suse131_linux/Makefile.common"
.include "../../mk/bsd.pkg.mk"
