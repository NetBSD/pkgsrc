# $NetBSD: Makefile,v 1.6 2014/09/07 12:26:40 obache Exp $

PKGNAME=	suse_locale-${SUSE_VERSION}
PKGREVISION=	2
CATEGORIES=	emulators
DISTFILES=	glibc-locale-2.3.5-40.${SUSE_ARCH}.rpm

CONFLICTS=	linux-locale-[0-9]*

MAINTAINER=	tonio@NetBSD.org
COMMENT=	Linux compatibility package with locale files

EMUL_MODULES.linux=	base

.include "../../emulators/suse100_linux/Makefile.common"
.include "../../mk/bsd.pkg.mk"
