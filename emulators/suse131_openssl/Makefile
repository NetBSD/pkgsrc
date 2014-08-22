# $NetBSD: Makefile,v 1.9.2.1 2014/08/22 17:13:34 tron Exp $

DISTNAME=	suse_openssl-${SUSE_VERSION}
PKGREVISION=	9
CATEGORIES=	emulators
RPMUPDPKGS+=	libopenssl1_0_0-1.0.1i-11.52.1.${SUSE_ARCH}

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Linux compatibility package for OpenSSL

EMUL_MODULES.linux=	base

.include "../../emulators/suse131_linux/Makefile.common"
.include "../../mk/bsd.pkg.mk"
