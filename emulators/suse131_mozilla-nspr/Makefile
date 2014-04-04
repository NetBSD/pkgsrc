# $NetBSD: Makefile,v 1.2 2014/04/04 10:02:24 obache Exp $

DISTNAME=	suse_mozilla-nspr-${SUSE_VERSION}
PKGREVISION=	1
CATEGORIES=	emulators
RPMUPDPKGS+=	mozilla-nspr-4.10.4-8.1.${SUSE_ARCH}

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Linux compatibility package for Mozilla NSPR

EMUL_MODULES.linux=	base

.include "../../emulators/suse131_linux/Makefile.common"
.include "../../mk/bsd.pkg.mk"
