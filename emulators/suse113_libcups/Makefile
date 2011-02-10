# $NetBSD: Makefile,v 1.3 2011/02/10 02:55:46 chs Exp $

DISTNAME=	suse_libcups-${SUSE_VERSION}
PKGREVISION=	1
CATEGORIES=	emulators
DISTFILES=	cups-libs-1.4.4-3.3.1.${SUSE_ARCH}.rpm

MAINTAINER=	chs@NetBSD.org
COMMENT=	Linux compatibility package for CUPS

EMUL_MODULES.linux=	openssl

.include "../../emulators/suse113_linux/Makefile.common"
.include "../../mk/bsd.pkg.mk"
