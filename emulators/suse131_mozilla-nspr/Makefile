# $NetBSD: Makefile,v 1.7 2015/02/16 10:15:49 jperkin Exp $

PKGNAME=	suse_mozilla-nspr-${SUSE_VERSION}
PKGREVISION=	3
CATEGORIES=	emulators
RPMUPDPKGS+=	mozilla-nspr-4.10.7-16.1.${SUSE_ARCH}

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Linux compatibility package for Mozilla NSPR

EMUL_MODULES.linux=	base

.include "../../emulators/suse131_linux/Makefile.common"
.include "../../mk/bsd.pkg.mk"
