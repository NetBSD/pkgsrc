# $NetBSD: Makefile,v 1.2.2.2 2012/04/25 18:08:42 tron Exp $

DISTNAME=	suse_openssl-${SUSE_VERSION}
PKGREVISION=	3
CATEGORIES=	emulators
RPMUPDPKGS+=	libopenssl1_0_0-1.0.0e-34.12.1.${SUSE_ARCH}

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Linux compatibility package for OpenSSL

EMUL_MODULES.linux=	base

.include "../../emulators/suse121_linux/Makefile.common"
.include "../../mk/bsd.pkg.mk"
