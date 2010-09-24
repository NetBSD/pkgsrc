# $NetBSD: Makefile,v 1.1.1.1 2010/09/24 01:27:53 chs Exp $

DISTNAME=	suse_compat-${SUSE_VERSION}
CATEGORIES=	emulators
DISTFILES+=	libjpeg6-6.2.0-3.1.${SUSE_ARCH}.rpm		\
		libstdc++33-3.3.3-22.1.${SUSE_ARCH}.rpm

MAINTAINER=	tonio@NetBSD.org
COMMENT=	Linux compatibility package with old shared libraries

EMUL_MODULES.linux=	base

.include "../../emulators/suse113_linux/Makefile.common"
.include "../../mk/bsd.pkg.mk"
