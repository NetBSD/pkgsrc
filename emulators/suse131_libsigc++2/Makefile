# $NetBSD: Makefile,v 1.3 2015/02/11 09:38:18 obache Exp $

DISTNAME=	suse_libsigc++2-${SUSE_VERSION}
CATEGORIES=	emulators
RPMPKGS+=	libsigc-2_0-0-2.3.1-2.1.2.${SUSE_ARCH}

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Linux compatibility package for libsigc++2

EMUL_MODULES.linux=	base

.include "../../emulators/suse131_linux/Makefile.common"
.include "../../mk/bsd.pkg.mk"
