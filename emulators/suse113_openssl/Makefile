# $NetBSD: Makefile,v 1.8 2012/01/19 15:54:55 chs Exp $

DISTNAME=	suse_openssl-${SUSE_VERSION}
PKGREVISION=	6
CATEGORIES=	emulators
DISTFILES=	libopenssl1_0_0-1.0.0-6.13.1.${SUSE_ARCH}.rpm

MAINTAINER=	chs@NetBSD.org
COMMENT=	Linux compatibility package for OpenSSL

EMUL_MODULES.linux=	base

.include "../../emulators/suse113_linux/Makefile.common"
.include "../../mk/bsd.pkg.mk"
