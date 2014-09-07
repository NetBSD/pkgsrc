# $NetBSD: Makefile,v 1.2 2014/09/07 12:26:44 obache Exp $

PKGNAME=	suse_libssh-${SUSE_VERSION}
CATEGORIES=	emulators
RPMPKGS+=	libssh2-1-1.4.3-7.1.2.${SUSE_ARCH}

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Linux compatibility package for libssh

EMUL_MODULES.linux=	base openssl

.include "../../emulators/suse131_linux/Makefile.common"
.include "../../mk/bsd.pkg.mk"
