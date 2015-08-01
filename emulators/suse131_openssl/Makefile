# $NetBSD: Makefile,v 1.16.4.1 2015/08/01 09:19:56 tron Exp $

PKGNAME=	suse_openssl-${SUSE_VERSION}
PKGREVISION=	13
CATEGORIES=	emulators
RPMUPDPKGS+=	libopenssl1_0_0-1.0.1k-11.72.1.${SUSE_ARCH}

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Linux compatibility package for OpenSSL

EMUL_MODULES.linux=	base

.include "../../emulators/suse131_linux/Makefile.common"
.include "../../mk/bsd.pkg.mk"
