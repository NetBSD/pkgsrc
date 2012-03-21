# $NetBSD: Makefile,v 1.1.1.1 2012/03/21 13:37:36 obache Exp $

DISTNAME=	suse_libcups-${SUSE_VERSION}
CATEGORIES=	emulators
RPMPKGS+=	cups-libs-1.5.0-2.1.3.${SUSE_ARCH}

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Linux compatibility package for CUPS

EMUL_MODULES.linux=	openssl

.include "../../emulators/suse121_linux/Makefile.common"
.include "../../mk/bsd.pkg.mk"
