# $NetBSD: Makefile,v 1.11 2007/10/26 15:06:19 joerg Exp $

DISTNAME=	pciutils-2.1.11
PKGREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	ftp://atrey.karlin.mff.cuni.cz/pub/linux/pci/ \
		ftp://ftp.kernel.org/pub/software/utils/pciutils/ \
		ftp://metalab.unc.edu/pub/Linux/hardware/

MAINTAINER=	cube@NetBSD.org
HOMEPAGE=	http://mj.ucw.cz/pciutils.shtml
COMMENT=	PCI bus manipulation utility similar to NetBSD pcictl(8)

PKG_DESTDIR_SUPPORT=	user-destdir

# subdir build in libs, followed by linking with it, without .WAIT
MAKE_JOBS_SAFE=	NO

USE_TOOLS+=	gmake

ONLY_FOR_PLATFORM+=	AIX-*-* FreeBSD-*-* Linux-*-* NetBSD-*-*

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "NetBSD"
PLIST_SUBST+=	PCIUTILS_LIBNAME="pciutils"
.else
PLIST_SUBST+=	PCIUTILS_LIBNAME="pci"
.endif

.include "../../mk/bsd.pkg.mk"
