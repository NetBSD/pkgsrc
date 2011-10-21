# $NetBSD: Makefile,v 1.7 2011/10/21 15:56:37 chs Exp $

DISTNAME=	suse_openssl-${SUSE_VERSION}
PKGREVISION=	5
CATEGORIES=	emulators
DISTFILES=	libopenssl1_0_0-1.0.0-6.11.1.${SUSE_ARCH}.rpm

MAINTAINER=	chs@NetBSD.org
COMMENT=	Linux compatibility package for OpenSSL

EMUL_MODULES.linux=	base

.include "../../emulators/suse113_linux/Makefile.common"
.include "../../mk/bsd.pkg.mk"
