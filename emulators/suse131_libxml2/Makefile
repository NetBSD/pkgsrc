# $NetBSD: Makefile,v 1.7 2015/02/11 09:38:18 obache Exp $

DISTNAME=	suse_libxml2-${SUSE_VERSION}
PKGREVISION=	3
CATEGORIES=	emulators
RPMUPDPKGS+=	libxml2-2-2.9.1-2.16.1.${SUSE_ARCH}

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Linux compatibility package for libxml2

EMUL_MODULES.linux=	base

.include "../../emulators/suse131_linux/Makefile.common"
.include "../../mk/bsd.pkg.mk"
