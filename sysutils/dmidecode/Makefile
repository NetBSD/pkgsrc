# $NetBSD: Makefile,v 1.32 2020/05/13 05:28:23 msaitoh Exp $
#

DISTNAME=	dmidecode-3.2
PKGREVISION=	7
EXTRACT_SUFX=	.tar.xz
CATEGORIES=	sysutils
MASTER_SITES=	http://download.savannah.gnu.org/releases/dmidecode/

MAINTAINER=	msaitoh@NetBSD.org
HOMEPAGE=	https://www.nongnu.org/dmidecode/
COMMENT=	Print out DMI (SMBIOS) table in human-readable format
LICENSE=	gnu-gpl-v2

PATCH_SITES=		http://git.savannah.gnu.org/cgit/dmidecode.git/patch/?id=
DIST_SUBDIR=		dmidecode-patches
PATCHFILES=		fde47bb227b8fa817c88d7e10a8eb771c46de1df
PATCHFILES+=		74dfb854b8199ddb0a27e89296fa565f4706cb9d
PATCHFILES+=		e12ec26e19e02281d3e7258c3aabb88a5cf5ec1d
PATCHFILES+=		1d0db85949a5bdd96375f6131d393a11204302a6
PATCHFILES+=		fd08479625b5845e4d725ab628628f7ebfccc407
PATCHFILES+=		65438a7ec0f4cddccf810136da6f280bd148af71
PATCHFILES+=		5bb7eb173b72256f70c6b3f3916d7a444be93340
PATCHFILES+=		557c3c373a9992d45d4358a6a2ccf53b03276f39
PATCH_DIST_STRIP=	-p1

MAKE_FLAGS+=	CFLAGS=${CFLAGS:Q}
MAKE_FLAGS+=	LDFLAGS=${LDFLAGS:Q}

ONLY_FOR_PLATFORM=	*-*-i386 *-*-x86_64 *-*-aarch64

.include "../../mk/bsd.pkg.mk"
