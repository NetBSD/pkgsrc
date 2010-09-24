# $NetBSD: Makefile,v 1.1.1.1 2010/09/24 01:28:09 chs Exp $

DISTNAME=	suse_openssl-${SUSE_VERSION}
CATEGORIES=	emulators
DISTFILES=	libopenssl1_0_0-1.0.0-5.4.${SUSE_ARCH}.rpm

MAINTAINER=	markd@NetBSD.org
COMMENT=	Linux compatibility package for OpenSSL

EMUL_MODULES.linux=	base

.include "../../emulators/suse113_linux/Makefile.common"
.include "../../mk/bsd.pkg.mk"
