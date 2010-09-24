# $NetBSD: Makefile,v 1.1.1.1 2010/09/24 01:28:00 chs Exp $

DISTNAME=	suse_libcups-${SUSE_VERSION}
CATEGORIES=	emulators
DISTFILES=	cups-libs-1.4.4-2.3.${SUSE_ARCH}.rpm

MAINTAINER=	markd@NetBSD.org
COMMENT=	Linux compatibility package for CUPS

EMUL_MODULES.linux=	openssl

.include "../../emulators/suse113_linux/Makefile.common"
.include "../../mk/bsd.pkg.mk"
