# $NetBSD: Makefile,v 1.9 2007/07/29 05:19:22 jlam Exp $

DISTNAME=	suse_vmware-${SUSE_VERSION}
PKGREVISION=	3
CATEGORIES=	emulators
DISTFILES=	grep-2.5.1-416.${SUSE_ARCH}.rpm

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Linux compatibility package to help run VMware

EMUL_PLATFORMS=		linux-i386
EMUL_MODULES.linux=	base x11
RPMIGNOREPATH=		usr

.include "../../emulators/suse91_linux/Makefile.common"
.include "../../mk/bsd.pkg.mk"
