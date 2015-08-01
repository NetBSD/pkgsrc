# $NetBSD: Makefile,v 1.4.4.1 2015/08/01 09:19:56 tron Exp $

PKGNAME=	suse_locale-${SUSE_VERSION}
PKGREVISION=	1
CATEGORIES=	emulators
RPMUPDPKGS+=	glibc-locale-2.18-4.35.1.${SUSE_ARCH}

CONFLICTS=	linux-locale-[0-9]*

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Linux compatibility package with locale files

EMUL_MODULES.linux=	base

.include "../../emulators/suse131_linux/Makefile.common"
.include "../../mk/bsd.pkg.mk"
