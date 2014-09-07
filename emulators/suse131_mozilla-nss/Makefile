# $NetBSD: Makefile,v 1.5 2014/09/07 12:26:44 obache Exp $

PKGNAME=	suse_mozilla-nss-${SUSE_VERSION}
PKGREVISION=	3
CATEGORIES=	emulators
RPMUPDPKGS+=	mozilla-nss-3.16.3-27.1.${SUSE_ARCH}

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Linux compatibility package for Mozilla NSS

EMUL_MODULES.linux=	nspr

.include "../../emulators/suse131_linux/Makefile.common"
.include "../../mk/bsd.pkg.mk"
