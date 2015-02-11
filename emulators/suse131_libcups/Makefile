# $NetBSD: Makefile,v 1.3 2015/02/11 09:38:17 obache Exp $

DISTNAME=	suse_libcups-${SUSE_VERSION}
CATEGORIES=	emulators
RPMPKGS+=	cups-libs-1.5.4-12.1.3.${SUSE_ARCH}

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Linux compatibility package for CUPS

EMUL_MODULES.linux=	openssl

.include "../../emulators/suse131_linux/Makefile.common"
.include "../../mk/bsd.pkg.mk"
