# $NetBSD: Makefile,v 1.2 2014/09/07 12:26:44 obache Exp $

PKGNAME=	suse_locale-${SUSE_VERSION}
CATEGORIES=	emulators
RPMPKGS+=	glibc-locale-2.18-4.4.1.${SUSE_ARCH}

CONFLICTS=	linux-locale-[0-9]*

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Linux compatibility package with locale files

EMUL_MODULES.linux=	base

.include "../../emulators/suse131_linux/Makefile.common"
.include "../../mk/bsd.pkg.mk"
