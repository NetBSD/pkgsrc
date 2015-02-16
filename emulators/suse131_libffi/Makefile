# $NetBSD: Makefile,v 1.4 2015/02/16 10:15:48 jperkin Exp $

PKGNAME=	suse_libffi-${SUSE_VERSION}
CATEGORIES=	emulators
RPMPKGS+=	libffi4-4.8.1_20130909-3.2.1.${SUSE_ARCH}

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Linux compatibility package for libffi

CONFLICTS+=	suse_gtk2<13.1nb1

EMUL_MODULES.linux=	base

.include "../../emulators/suse131_linux/Makefile.common"
.include "../../mk/bsd.pkg.mk"
