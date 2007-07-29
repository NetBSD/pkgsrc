# $NetBSD: Makefile,v 1.6 2007/07/29 05:18:57 jlam Exp $

DISTNAME=	suse_openssl-${SUSE_VERSION}
PKGREVISION=	4
CATEGORIES=	emulators
DISTFILES=	openssl-0.9.7g-2.12.${SUSE_ARCH}.rpm

MAINTAINER=	markd@NetBSD.org
COMMENT=	Linux compatibility package for OpenSSL

EMUL_MODULES.linux=	base

.include "../../emulators/suse100_linux/Makefile.common"
.include "../../mk/bsd.pkg.mk"
