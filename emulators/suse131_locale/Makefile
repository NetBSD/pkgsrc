# $NetBSD: Makefile,v 1.6 2015/08/17 16:13:51 wiz Exp $

PKGNAME=	suse_locale-${SUSE_VERSION}
PKGREVISION=	2
CATEGORIES=	emulators
RPMUPDPKGS+=	glibc-locale-2.18-4.38.1.${SUSE_ARCH}

CONFLICTS=	linux-locale-[0-9]*

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Linux compatibility package with locale files

EMUL_MODULES.linux=	base

.include "../../emulators/suse131_linux/Makefile.common"
.include "../../mk/bsd.pkg.mk"
