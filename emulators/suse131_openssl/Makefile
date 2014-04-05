# $NetBSD: Makefile,v 1.3.2.1 2014/04/05 15:59:58 tron Exp $

DISTNAME=	suse_openssl-${SUSE_VERSION}
PKGREVISION=	3
CATEGORIES=	emulators
RPMUPDPKGS+=	libopenssl1_0_0-1.0.1e-11.28.1.${SUSE_ARCH}

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Linux compatibility package for OpenSSL

EMUL_MODULES.linux=	base

.include "../../emulators/suse131_linux/Makefile.common"
.include "../../mk/bsd.pkg.mk"
