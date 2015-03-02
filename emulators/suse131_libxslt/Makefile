# $NetBSD: Makefile,v 1.1 2015/03/02 16:54:55 tnn Exp $

PKGNAME=	suse_libxslt-${SUSE_VERSION}
CATEGORIES=	emulators
RPMPKGS+=	libxslt1-1.1.28-5.1.2.${SUSE_ARCH}

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Linux compatibility package for libxslt

EMUL_MODULES.linux=	base

.include "../../emulators/suse131_linux/Makefile.common"
.include "../../mk/bsd.pkg.mk"
