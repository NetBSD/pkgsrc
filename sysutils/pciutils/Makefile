# $NetBSD: Makefile,v 1.57 2024/02/25 15:08:50 wiz Exp $

DISTNAME=	pciutils-3.11.1
CATEGORIES=	sysutils
MASTER_SITES+=	https://www.kernel.org/pub/software/utils/pciutils/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://mj.ucw.cz/pciutils.shtml
COMMENT=	PCI bus manipulation utility similar to NetBSD pcictl(8)
LICENSE=	gnu-gpl-v2

MAKE_JOBS_SAFE=		no
ONLY_FOR_PLATFORM=	AIX-*-* Darwin-*-* FreeBSD-*-* Linux-*-* NetBSD-*-*
ONLY_FOR_PLATFORM+=	DragonFly-*-* OpenBSD-*-* SunOS-5.11-* Haiku-*-*

CFLAGS+=		-fPIC
MAKE_FLAGS+=		PREFIX=${PREFIX:Q}
MAKE_FLAGS+=		SHAREDIR=${PREFIX:Q}/share/pciutils
MAKE_FLAGS+=		MANDIR=${PREFIX:Q}/${PKGMANDIR}
MAKE_FLAGS+=		CC=${CC:Q}
MAKE_FLAGS+=		CFLAGS=${CFLAGS:Q}
MAKE_FLAGS+=		LDFLAGS=${LDFLAGS:Q}
MAKE_FLAGS+=		SHARED=yes

INSTALL_TARGET=		install install-lib
USE_TOOLS+=		gmake
REPLACE_SH=		*.sh

PKGCONFIG_OVERRIDE=	lib/libpci.pc.in

# "error: 'for' loop initial declarations are only allowed in C99 mode"
# cannot be standard c99, uses symbol versions
FORCE_C_STD=		gnu99

.include "../../sysutils/pciutils/libname.mk"

PLIST_SUBST+=		PCIUTILS_LIBNAME=${PCIUTILS_LIBNAME}

SUBST_CLASSES=		pc
SUBST_FILES.pc=		lib/libpci.pc.in
SUBST_MESSAGE.pc=	Fixing library link specification in pkg-config file.
SUBST_STAGE.pc=		pre-configure
SUBST_VARS.pc=		PCIUTILS_LIBNAME

SUBST_CLASSES.SunOS+=	dns
SUBST_MESSAGE.dns=	Disabling DNS support on Solaris
SUBST_STAGE.dns=	pre-configure
SUBST_FILES.dns=	Makefile
SUBST_SED.dns=		-e 's/^DNS=/DNS=no/'

BUILDLINK_TRANSFORM.SunOS+=	rm:-Wl,--version-script=libpci.ver

.include "../../mk/bsd.pkg.mk"
