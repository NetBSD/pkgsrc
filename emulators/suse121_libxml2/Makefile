# $NetBSD: Makefile,v 1.4.2.1 2012/12/18 17:46:42 tron Exp $

DISTNAME=	suse_libxml2-${SUSE_VERSION}
PKGREVISION=	4
CATEGORIES=	emulators
RPMUPDPKGS+=	libxml2-2.7.8+git20110708-3.15.1.${SUSE_ARCH}

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Linux compatibility package for libxml2

EMUL_MODULES.linux=	base

.include "../../emulators/suse121_linux/Makefile.common"
.include "../../mk/bsd.pkg.mk"
