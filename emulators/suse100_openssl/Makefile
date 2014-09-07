# $NetBSD: Makefile,v 1.8 2014/09/07 12:26:40 obache Exp $

PKGNAME=	suse_openssl-${SUSE_VERSION}
PKGREVISION=	5
CATEGORIES=	emulators
DISTFILES=	openssl-0.9.7g-2.15.${SUSE_ARCH}.rpm

MAINTAINER=	markd@NetBSD.org
COMMENT=	Linux compatibility package for OpenSSL

EMUL_MODULES.linux=	base

.include "../../emulators/suse100_linux/Makefile.common"
.include "../../mk/bsd.pkg.mk"
