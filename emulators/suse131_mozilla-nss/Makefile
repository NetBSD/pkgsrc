# $NetBSD: Makefile,v 1.1 2013/12/12 02:34:28 obache Exp $

DISTNAME=	suse_mozilla-nss-${SUSE_VERSION}
CATEGORIES=	emulators
RPMUPDPKGS+=	mozilla-nss-3.15.3-4.2.${SUSE_ARCH}

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Linux compatibility package for Mozilla NSS

EMUL_MODULES.linux=	nspr

.include "../../emulators/suse131_linux/Makefile.common"
.include "../../mk/bsd.pkg.mk"
