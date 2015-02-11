# $NetBSD: Makefile,v 1.7 2015/02/11 09:38:19 obache Exp $

DISTNAME=	suse_mozilla-nss-${SUSE_VERSION}
PKGREVISION=	4
CATEGORIES=	emulators
RPMUPDPKGS+=	mozilla-nss-3.17.1-43.1.${SUSE_ARCH}

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Linux compatibility package for Mozilla NSS

EMUL_MODULES.linux=	nspr

.include "../../emulators/suse131_linux/Makefile.common"
.include "../../mk/bsd.pkg.mk"
