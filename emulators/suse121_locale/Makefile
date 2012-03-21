# $NetBSD: Makefile,v 1.1.1.1 2012/03/21 13:40:16 obache Exp $

DISTNAME=	suse_locale-${SUSE_VERSION}
CATEGORIES=	emulators
RPMUPDPKGS+=	glibc-locale-2.14.1-14.25.1.${SUSE_ARCH}

CONFLICTS=	linux-locale-[0-9]*

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Linux compatibility package with locale files

EMUL_MODULES.linux=	base

.include "../../emulators/suse121_linux/Makefile.common"
.include "../../mk/bsd.pkg.mk"
