# $NetBSD: Makefile,v 1.5 2011/04/03 14:01:36 chs Exp $

DISTNAME=	suse_openssl-${SUSE_VERSION}
PKGREVISION=	3
CATEGORIES=	emulators
DISTFILES=	libopenssl1_0_0-1.0.0-6.7.1.${SUSE_ARCH}.rpm

MAINTAINER=	chs@NetBSD.org
COMMENT=	Linux compatibility package for OpenSSL

EMUL_MODULES.linux=	base

.include "../../emulators/suse113_linux/Makefile.common"
.include "../../mk/bsd.pkg.mk"
