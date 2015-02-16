# $NetBSD: Makefile,v 1.10 2015/02/16 10:15:44 jperkin Exp $

PKGNAME=	suse_openssl-${SUSE_VERSION}
PKGREVISION=	5
CATEGORIES=	emulators
DISTFILES=	openssl-0.9.7g-2.15.${SUSE_ARCH}.rpm

MAINTAINER=	markd@NetBSD.org
COMMENT=	Linux compatibility package for OpenSSL

EMUL_MODULES.linux=	base

.include "../../emulators/suse100_linux/Makefile.common"
.include "../../mk/bsd.pkg.mk"
