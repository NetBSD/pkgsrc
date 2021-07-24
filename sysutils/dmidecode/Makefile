# $NetBSD: Makefile,v 1.36 2021/07/24 13:23:52 jmcneill Exp $
#

DISTNAME=	dmidecode-3.3
PKGREVISION=	2
EXTRACT_SUFX=	.tar.xz
CATEGORIES=	sysutils
MASTER_SITES=	https://download.savannah.gnu.org/releases/dmidecode/

MAINTAINER=	msaitoh@NetBSD.org
HOMEPAGE=	https://www.nongnu.org/dmidecode/
COMMENT=	Print out DMI (SMBIOS) table in human-readable format
LICENSE=	gnu-gpl-v2

PATCH_SITES=		https://git.savannah.gnu.org/cgit/dmidecode.git/patch/?id=
DIST_SUBDIR=		dmidecode-patches
PATCHFILES=		1117390ccd9cea139638db6f460bb6de70e28f94
PATCHFILES+=		11e134e54d15e67a64c39a623f492a28df922517
PATCH_DIST_STRIP=	-p1

MAKE_FLAGS+=	CFLAGS=${CFLAGS:Q}
MAKE_FLAGS+=	LDFLAGS=${LDFLAGS:Q}

ONLY_FOR_PLATFORM=	*-*-i386 *-*-x86_64 *-*-aarch64*

.include "../../mk/bsd.pkg.mk"
