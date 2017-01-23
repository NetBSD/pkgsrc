# $NetBSD: Makefile,v 1.18 2017/01/23 15:55:55 msaitoh Exp $
#

DISTNAME=	dmidecode-3.0
PKGREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	http://download.savannah.gnu.org/releases/dmidecode/

MAINTAINER=	msaitoh@NetBSD.org
HOMEPAGE=	http://www.nongnu.org/dmidecode/
COMMENT=	Print out DMI (SMBIOS) table in human-readable format
LICENSE=	gnu-gpl-v2

PATCH_SITES=	http://git.savannah.gnu.org/cgit/dmidecode.git/patch/?id=
DIST_SUBDIR=	dmidecode-patches
PATCHFILES=	33b5aafc6ee6b5de9f2526fb1cf4b14d1e16e4f0
PATCHFILES+=	bf7bad24ce141dab5b5acc3ffb98ce5fe4a8e0f9
PATCHFILES+=	de9a74e1c60210bee229fcf55b1678a99d1b44dd
PATCHFILES+=	364055211b1956539c6a6268e111e244e1292c8c
PATCHFILES+=	ab02b117511230e46bbef7febbd854b9c832c13c
PATCHFILES+=	cff11afa886a0147d734b650755d232b5e7f2099
PATCHFILES+=	23aa50565a65c98fc452ed8ffdffb49b6504941d
PATCHFILES+=	12fbde92a26da61eda9f2ff0ba3c316779163f10

PATCH_DIST_STRIP= -p1

MAKE_FLAGS+=	CFLAGS=${CFLAGS:Q}
MAKE_FLAGS+=	LDFLAGS=${LDFLAGS:Q}

ONLY_FOR_PLATFORM=	*-*-i386 *-*-x86_64

.include "../../mk/bsd.pkg.mk"
