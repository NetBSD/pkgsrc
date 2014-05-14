# $NetBSD: Makefile,v 1.8 2014/05/14 09:31:44 obache Exp $

DISTNAME=	suse_openssl-${SUSE_VERSION}
PKGREVISION=	7
CATEGORIES=	emulators
RPMUPDPKGS+=	libopenssl1_0_0-1.0.1g-11.44.1.${SUSE_ARCH}

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Linux compatibility package for OpenSSL

EMUL_MODULES.linux=	base

.include "../../emulators/suse131_linux/Makefile.common"
.include "../../mk/bsd.pkg.mk"
