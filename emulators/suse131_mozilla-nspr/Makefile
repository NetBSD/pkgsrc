# $NetBSD: Makefile,v 1.1 2013/12/12 02:34:28 obache Exp $

DISTNAME=	suse_mozilla-nspr-${SUSE_VERSION}
CATEGORIES=	emulators
RPMUPDPKGS+=	mozilla-nspr-4.10.2-4.1.${SUSE_ARCH}

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Linux compatibility package for Mozilla NSPR

EMUL_MODULES.linux=	base

.include "../../emulators/suse131_linux/Makefile.common"
.include "../../mk/bsd.pkg.mk"
