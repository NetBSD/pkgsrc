# $NetBSD: Makefile,v 1.22 2012/12/19 14:05:26 jperkin Exp $

DISTNAME=	pciutils-3.1.10
CATEGORIES=	sysutils
MASTER_SITES=	ftp://atrey.karlin.mff.cuni.cz/pub/linux/pci/ \
		ftp://ftp.kernel.org/pub/software/utils/pciutils/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://mj.ucw.cz/pciutils.shtml
COMMENT=	PCI bus manipulation utility similar to NetBSD pcictl(8)
LICENSE=	gnu-gpl-v2

MAKE_JOBS_SAFE=		no
ONLY_FOR_PLATFORM=	AIX-*-* FreeBSD-*-* Linux-*-* NetBSD-*-*
ONLY_FOR_PLATFORM+=	DragonFly-*-* OpenBSD-*-* SunOS-5.11-*

INSTALL_TARGET=		install install-lib
USE_TOOLS+=		gmake pkg-config
REPLACE_SH=		*.sh

PKGCONFIG_OVERRIDE=	lib/libpci.pc.in

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "NetBSD"
PCIUTILS_LIBNAME=	pciutils
.else
PCIUTILS_LIBNAME=	pci
.endif

PLIST_SUBST+=		PCIUTILS_LIBNAME=${PCIUTILS_LIBNAME}

SUBST_CLASSES=		pc
SUBST_FILES.pc=		lib/libpci.pc.in
SUBST_MESSAGE.pc=	Fixing library link specification in pkg-config file.
SUBST_STAGE.pc=		pre-configure
SUBST_VARS.pc=		PCIUTILS_LIBNAME

.if ${OPSYS} == "SunOS"
SUBST_CLASSES=		dns
SUBST_MESSAGE.dns=	Disabling DNS support on Solaris
SUBST_STAGE.dns=	pre-configure
SUBST_FILES.dns=	Makefile
SUBST_SED.dns=		-e 's/^DNS=/DNS=no/'
.endif

.include "../../mk/bsd.pkg.mk"
