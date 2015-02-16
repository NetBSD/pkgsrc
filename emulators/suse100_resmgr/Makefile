# $NetBSD: Makefile,v 1.5 2015/02/16 10:15:44 jperkin Exp $

PKGNAME=	suse_resmgr-${SUSE_VERSION}
PKGREVISION=	1
CATEGORIES=	emulators
DISTFILES=	resmgr-0.9.8_SVNr57-2.3.${SUSE_ARCH}.rpm

MAINTAINER=	tonio@NetBSD.org
COMMENT=	Linux compatibility package for resmgr

EMUL_MODULES.linux=	base

.include "../../emulators/suse100_linux/Makefile.common"
.include "../../mk/bsd.pkg.mk"
