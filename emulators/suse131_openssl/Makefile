# $NetBSD: Makefile,v 1.1.2.1 2014/01/05 20:20:36 spz Exp $

DISTNAME=	suse_openssl-${SUSE_VERSION}
PKGREVISION=	1
CATEGORIES=	emulators
RPMUPDPKGS+=	libopenssl1_0_0-1.0.1e-11.10.1.${SUSE_ARCH}

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Linux compatibility package for OpenSSL

EMUL_MODULES.linux=	base

.include "../../emulators/suse131_linux/Makefile.common"
.include "../../mk/bsd.pkg.mk"
