# $NetBSD: Makefile,v 1.7.4.1 2015/08/01 09:19:56 tron Exp $

PKGNAME=	suse_mozilla-nspr-${SUSE_VERSION}
PKGREVISION=	4
CATEGORIES=	emulators
RPMUPDPKGS+=	mozilla-nspr-4.10.8-22.1.${SUSE_ARCH}

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Linux compatibility package for Mozilla NSPR

EMUL_MODULES.linux=	base

.include "../../emulators/suse131_linux/Makefile.common"
.include "../../mk/bsd.pkg.mk"
