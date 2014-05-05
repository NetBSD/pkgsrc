# $NetBSD: Makefile,v 1.3.2.3 2014/05/05 17:10:18 tron Exp $

DISTNAME=	suse_openssl-${SUSE_VERSION}
PKGREVISION=	6
CATEGORIES=	emulators
RPMUPDPKGS+=	libopenssl1_0_0-1.0.1g-11.40.1.${SUSE_ARCH}

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Linux compatibility package for OpenSSL

EMUL_MODULES.linux=	base

.include "../../emulators/suse131_linux/Makefile.common"
.include "../../mk/bsd.pkg.mk"
