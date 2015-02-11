# $NetBSD: Makefile,v 1.3 2015/02/11 09:38:18 obache Exp $

DISTNAME=	suse_locale-${SUSE_VERSION}
CATEGORIES=	emulators
RPMPKGS+=	glibc-locale-2.18-4.4.1.${SUSE_ARCH}

CONFLICTS=	linux-locale-[0-9]*

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Linux compatibility package with locale files

EMUL_MODULES.linux=	base

.include "../../emulators/suse131_linux/Makefile.common"
.include "../../mk/bsd.pkg.mk"
