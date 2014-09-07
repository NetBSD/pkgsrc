# $NetBSD: Makefile,v 1.2 2014/09/07 12:26:39 obache Exp $

PKGNAME=	suse_libidn-${SUSE_VERSION}
CATEGORIES=	emulators
DISTFILES+=	libidn-0.5.9-5.${SUSE_ARCH}.rpm

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Linux compatibility package for libidn

EMUL_MODULES.linux=	base

.include "../../emulators/suse100_linux/Makefile.common"
.include "../../mk/bsd.pkg.mk"
