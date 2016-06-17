# $NetBSD: Makefile,v 1.9 2016/06/17 17:21:39 tsutsui Exp $

PKGNAME=	suse_mozilla-nspr-${SUSE_VERSION}
PKGREVISION=	5
CATEGORIES=	emulators
RPMUPDPKGS+=	mozilla-nspr-4.12-34.1.${SUSE_ARCH}

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Linux compatibility package for Mozilla NSPR

EMUL_MODULES.linux=	base

.include "../../emulators/suse131_linux/Makefile.common"
.include "../../mk/bsd.pkg.mk"
