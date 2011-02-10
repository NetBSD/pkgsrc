# $NetBSD: Makefile,v 1.2 2011/02/10 02:55:48 chs Exp $

DISTNAME=	suse_vmware-${SUSE_VERSION}
CATEGORIES=	emulators
DISTFILES=	grep-2.5.4-7.1.${SUSE_ARCH}.rpm

MAINTAINER=	chs@NetBSD.org
COMMENT=	Linux compatibility package to help run VMware

EMUL_MODULES.linux=	base x11
RPMIGNOREPATH=		usr

.include "../../emulators/suse113_linux/Makefile.common"
.include "../../mk/bsd.pkg.mk"
