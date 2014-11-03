# $NetBSD: Makefile,v 1.5 2014/11/03 08:33:47 obache Exp $

PKGNAME=	suse_mozilla-nspr-${SUSE_VERSION}
PKGREVISION=	3
CATEGORIES=	emulators
RPMUPDPKGS+=	mozilla-nspr-4.10.7-16.1.${SUSE_ARCH}

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Linux compatibility package for Mozilla NSPR

EMUL_MODULES.linux=	base

.include "../../emulators/suse131_linux/Makefile.common"
.include "../../mk/bsd.pkg.mk"
