# $NetBSD: Makefile,v 1.9 2015/02/16 10:15:43 jperkin Exp $

PKGNAME=	suse_libcups-${SUSE_VERSION}
PKGREVISION=	4
CATEGORIES=	emulators
DISTFILES=	cups-libs-1.1.23-21.16.${SUSE_ARCH}.rpm

MAINTAINER=	markd@NetBSD.org
COMMENT=	Linux compatibility package for CUPS

EMUL_MODULES.linux=	openssl

.include "../../emulators/suse100_linux/Makefile.common"
.include "../../mk/bsd.pkg.mk"
