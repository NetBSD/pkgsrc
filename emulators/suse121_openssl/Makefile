# $NetBSD: Makefile,v 1.1.1.1 2012/03/21 13:40:40 obache Exp $

DISTNAME=	suse_openssl-${SUSE_VERSION}
CATEGORIES=	emulators
RPMUPDPKGS+=	libopenssl1_0_0-1.0.0e-34.5.1.${SUSE_ARCH}

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Linux compatibility package for OpenSSL

EMUL_MODULES.linux=	base

.include "../../emulators/suse121_linux/Makefile.common"
.include "../../mk/bsd.pkg.mk"
