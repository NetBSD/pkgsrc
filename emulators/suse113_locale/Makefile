# $NetBSD: Makefile,v 1.1.1.1 2010/09/24 01:28:07 chs Exp $

DISTNAME=	suse_locale-${SUSE_VERSION}
CATEGORIES=	emulators
DISTFILES=	glibc-locale-2.11.2-2.4.${SUSE_ARCH}.rpm

CONFLICTS=	linux-locale-[0-9]*

MAINTAINER=	tonio@NetBSD.org
COMMENT=	Linux compatibility package with locale files

EMUL_MODULES.linux=	base

.include "../../emulators/suse113_linux/Makefile.common"
.include "../../mk/bsd.pkg.mk"
