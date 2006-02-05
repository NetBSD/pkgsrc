# $NetBSD: Makefile,v 1.8 2006/02/05 23:10:56 joerg Exp $

DISTNAME=	pciutils-2.1.11
PKGREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	ftp://atrey.karlin.mff.cuni.cz/pub/linux/pci/ \
		ftp://ftp.kernel.org/pub/software/utils/pciutils/ \
		ftp://metalab.unc.edu/pub/Linux/hardware/

MAINTAINER=	cube@NetBSD.org
HOMEPAGE=	http://atrey.karlin.mff.cuni.cz/~mj/pciutils.shtml
COMMENT=	PCI bus manipulation utility similar to NetBSD pcictl(8)

USE_TOOLS+=	gmake

ONLY_FOR_PLATFORM+=	AIX-*-* FreeBSD-*-* Linux-*-* NetBSD-*-*

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "NetBSD"
PLIST_SUBST+=	PCIUTILS_LIBNAME="pciutils"
.else
PLIST_SUBST+=	PCIUTILS_LIBNAME="pci"
.endif

.include "../../mk/bsd.pkg.mk"
