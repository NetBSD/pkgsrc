# $NetBSD: Makefile,v 1.1 2013/12/05 11:42:16 obache Exp $

DISTNAME=	suse_libjson-${SUSE_VERSION}
CATEGORIES=	emulators
RPMPKGS+=	libjson0-0.10-3.1.2.${SUSE_ARCH}

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Linux compatibility package for libjson

EMUL_MODULES.linux=	base

.include "../../emulators/suse131_linux/Makefile.common"
.include "../../mk/bsd.pkg.mk"
