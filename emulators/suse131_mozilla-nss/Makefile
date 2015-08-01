# $NetBSD: Makefile,v 1.8.4.1 2015/08/01 09:19:56 tron Exp $

PKGNAME=	suse_mozilla-nss-${SUSE_VERSION}
PKGREVISION=	5
CATEGORIES=	emulators
RPMUPDPKGS+=	mozilla-nss-3.19.2-59.1.${SUSE_ARCH}

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Linux compatibility package for Mozilla NSS

EMUL_MODULES.linux=	nspr

.include "../../emulators/suse131_linux/Makefile.common"
.include "../../mk/bsd.pkg.mk"
