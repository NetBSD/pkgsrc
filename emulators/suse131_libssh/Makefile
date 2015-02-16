# $NetBSD: Makefile,v 1.4 2015/02/16 10:15:49 jperkin Exp $

PKGNAME=	suse_libssh-${SUSE_VERSION}
CATEGORIES=	emulators
RPMPKGS+=	libssh2-1-1.4.3-7.1.2.${SUSE_ARCH}

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Linux compatibility package for libssh

EMUL_MODULES.linux=	base openssl

.include "../../emulators/suse131_linux/Makefile.common"
.include "../../mk/bsd.pkg.mk"
