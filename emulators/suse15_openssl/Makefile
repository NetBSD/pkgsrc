# $NetBSD: Makefile,v 1.1 2022/10/02 17:17:19 wiz Exp $

PKGNAME=	suse_openssl-${SUSE_VERSION}
CATEGORIES=	emulators
RPMPKGS+=	libopenssl1_0_0-1.0.2p-150000.3.56.1.${SUSE_ARCH}

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Linux compatibility package for OpenSSL

EMUL_MODULES.linux=	base

.include "../../emulators/suse15_linux/Makefile.common"
.include "../../mk/bsd.pkg.mk"
