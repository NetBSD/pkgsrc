# $NetBSD: Makefile,v 1.5 2015/07/28 08:49:15 wiz Exp $

PKGNAME=	suse_libssh-${SUSE_VERSION}
PKGREVISION=	1
CATEGORIES=	emulators
RPMUPDPKGS+=	libssh2-1-1.5.0-7.4.1.${SUSE_ARCH}

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Linux compatibility package for libssh

EMUL_MODULES.linux=	base openssl

.include "../../emulators/suse131_linux/Makefile.common"
.include "../../mk/bsd.pkg.mk"
