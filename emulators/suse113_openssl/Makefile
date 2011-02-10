# $NetBSD: Makefile,v 1.4 2011/02/10 02:55:48 chs Exp $

DISTNAME=	suse_openssl-${SUSE_VERSION}
PKGREVISION=	2
CATEGORIES=	emulators
DISTFILES=	libopenssl1_0_0-1.0.0-6.5.1.${SUSE_ARCH}.rpm

MAINTAINER=	chs@NetBSD.org
COMMENT=	Linux compatibility package for OpenSSL

EMUL_MODULES.linux=	base

.include "../../emulators/suse113_linux/Makefile.common"
.include "../../mk/bsd.pkg.mk"
