# $NetBSD: Makefile,v 1.2 2011/02/10 02:55:48 chs Exp $

DISTNAME=	suse_openmotif-${SUSE_VERSION}
CATEGORIES=	emulators
DISTFILES+=	openmotif-libs-2.3.2-2.8.${SUSE_ARCH}.rpm

MAINTAINER=	chs@NetBSD.org
COMMENT=	Linux compatibility package for OpenMotif

EMUL_MODULES.linux=	x11

.include "../../emulators/suse113_linux/Makefile.common"
.include "../../mk/bsd.pkg.mk"
