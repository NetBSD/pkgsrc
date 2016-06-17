# $NetBSD: Makefile,v 1.8 2016/06/17 17:21:38 tsutsui Exp $

PKGNAME=	suse_locale-${SUSE_VERSION}
PKGREVISION=	4
CATEGORIES=	emulators
RPMUPDPKGS+=	glibc-locale-2.18-4.44.1.${SUSE_ARCH}

CONFLICTS=	linux-locale-[0-9]*

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Linux compatibility package with locale files

EMUL_MODULES.linux=	base

.include "../../emulators/suse131_linux/Makefile.common"
.include "../../mk/bsd.pkg.mk"
