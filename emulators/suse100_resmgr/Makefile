# $NetBSD: Makefile,v 1.3 2014/09/07 12:26:40 obache Exp $

PKGNAME=	suse_resmgr-${SUSE_VERSION}
PKGREVISION=	1
CATEGORIES=	emulators
DISTFILES=	resmgr-0.9.8_SVNr57-2.3.${SUSE_ARCH}.rpm

MAINTAINER=	tonio@NetBSD.org
COMMENT=	Linux compatibility package for resmgr

EMUL_MODULES.linux=	base

.include "../../emulators/suse100_linux/Makefile.common"
.include "../../mk/bsd.pkg.mk"
