# $NetBSD: Makefile,v 1.1 2013/12/05 11:42:16 obache Exp $

DISTNAME=	suse_openssl-${SUSE_VERSION}
CATEGORIES=	emulators
RPMPKGS+=	libopenssl1_0_0-1.0.1e-11.2.1.${SUSE_ARCH}

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Linux compatibility package for OpenSSL

EMUL_MODULES.linux=	base

.include "../../emulators/suse131_linux/Makefile.common"
.include "../../mk/bsd.pkg.mk"
