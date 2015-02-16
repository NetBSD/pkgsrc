# $NetBSD: Makefile,v 1.4 2015/02/16 10:15:45 jperkin Exp $

PKGNAME=	suse_libcups-${SUSE_VERSION}
CATEGORIES=	emulators
RPMPKGS+=	cups-libs-1.5.0-2.1.3.${SUSE_ARCH}

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Linux compatibility package for CUPS

EMUL_MODULES.linux=	openssl

.include "../../emulators/suse121_linux/Makefile.common"
.include "../../mk/bsd.pkg.mk"
