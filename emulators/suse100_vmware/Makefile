# $NetBSD: Makefile,v 1.2 2007/07/29 05:19:00 jlam Exp $

DISTNAME=	suse_vmware-${SUSE_VERSION}
PKGREVISION=	1
CATEGORIES=	emulators
DISTFILES=	grep-2.5.1a-5.${SUSE_ARCH}.rpm

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Linux compatibility package to help run VMware

EMUL_MODULES.linux=	base x11
RPMIGNOREPATH=		usr

.include "../../emulators/suse100_linux/Makefile.common"
.include "../../mk/bsd.pkg.mk"
