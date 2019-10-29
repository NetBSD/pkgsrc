# $NetBSD: Makefile,v 1.28 2019/10/29 17:27:51 msaitoh Exp $
#

DISTNAME=	dmidecode-3.2
PKGREVISION=	5
EXTRACT_SUFX=	.tar.xz
CATEGORIES=	sysutils
MASTER_SITES=	http://download.savannah.gnu.org/releases/dmidecode/

MAINTAINER=	msaitoh@NetBSD.org
HOMEPAGE=	http://www.nongnu.org/dmidecode/
COMMENT=	Print out DMI (SMBIOS) table in human-readable format
LICENSE=	gnu-gpl-v2

PATCH_SITES=	http://git.savannah.gnu.org/cgit/dmidecode.git/patch/?id=
DIST_SUBDIR=	dmidecode-patches
PATCHFILES=	fde47bb227b8fa817c88d7e10a8eb771c46de1df
PATCHFILES+=	74dfb854b8199ddb0a27e89296fa565f4706cb9d
PATCHFILES+=	e12ec26e19e02281d3e7258c3aabb88a5cf5ec1d
PATCHFILES+=	1d0db85949a5bdd96375f6131d393a11204302a6
PATCHFILES+=	fd08479625b5845e4d725ab628628f7ebfccc407
PATCH_DIST_STRIP= -p1

MAKE_FLAGS+=	CFLAGS=${CFLAGS:Q}
MAKE_FLAGS+=	LDFLAGS=${LDFLAGS:Q}

ONLY_FOR_PLATFORM=	*-*-i386 *-*-x86_64 *-*-aarch64

.include "../../mk/bsd.pkg.mk"
