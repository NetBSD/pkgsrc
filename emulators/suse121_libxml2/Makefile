# $NetBSD: Makefile,v 1.7 2013/05/02 09:15:07 obache Exp $

DISTNAME=	suse_libxml2-${SUSE_VERSION}
PKGREVISION=	6
CATEGORIES=	emulators
RPMUPDPKGS+=	libxml2-2.7.8+git20110708-3.24.1.${SUSE_ARCH}

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Linux compatibility package for libxml2

EMUL_MODULES.linux=	base

.include "../../emulators/suse121_linux/Makefile.common"
.include "../../mk/bsd.pkg.mk"
