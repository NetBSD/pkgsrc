# $NetBSD: Makefile,v 1.10 2016/06/17 17:21:39 tsutsui Exp $

PKGNAME=	suse_mozilla-nss-${SUSE_VERSION}
PKGREVISION=	6
CATEGORIES=	emulators
RPMUPDPKGS+=	mozilla-nss-3.23-80.1.${SUSE_ARCH}

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Linux compatibility package for Mozilla NSS

EMUL_MODULES.linux=	nspr

.include "../../emulators/suse131_linux/Makefile.common"
.include "../../mk/bsd.pkg.mk"
