# $NetBSD: Makefile,v 1.1 2022/10/02 17:17:19 wiz Exp $

PKGNAME=	suse_locale-${SUSE_VERSION}
CATEGORIES=	emulators
RPMPKGS+=	glibc-locale-2.31-150300.37.1.${SUSE_ARCH}

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Linux compatibility package with locale files

EMUL_MODULES.linux=	base

.include "../../emulators/suse15_linux/Makefile.common"
.include "../../mk/bsd.pkg.mk"
