# $NetBSD: Makefile,v 1.1 2013/12/05 11:42:16 obache Exp $

DISTNAME=	suse_libwrap-${SUSE_VERSION}
CATEGORIES=	emulators
RPMPKGS+=	libwrap0-7.6-881.1.2.${SUSE_ARCH}

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Linux compatibility package for libwrap

EMUL_MODULES.linux=	base

.include "../../emulators/suse131_linux/Makefile.common"
.include "../../mk/bsd.pkg.mk"
