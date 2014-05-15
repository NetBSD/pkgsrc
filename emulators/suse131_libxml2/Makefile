# $NetBSD: Makefile,v 1.3 2014/05/15 18:39:28 wiz Exp $

DISTNAME=	suse_libxml2-${SUSE_VERSION}
PKGREVISION=	1
CATEGORIES=	emulators
RPMUPDPKGS+=	libxml2-2-2.9.1-2.4.1.${SUSE_ARCH}

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Linux compatibility package for libxml2

EMUL_MODULES.linux=	base

.include "../../emulators/suse131_linux/Makefile.common"
.include "../../mk/bsd.pkg.mk"
