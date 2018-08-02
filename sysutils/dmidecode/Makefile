# $NetBSD: Makefile,v 1.22 2018/08/02 02:45:50 msaitoh Exp $
#

DISTNAME=	dmidecode-3.1
PKGREVISION=	3
CATEGORIES=	sysutils
MASTER_SITES=	http://download.savannah.gnu.org/releases/dmidecode/

MAINTAINER=	msaitoh@NetBSD.org
HOMEPAGE=	http://www.nongnu.org/dmidecode/
COMMENT=	Print out DMI (SMBIOS) table in human-readable format
LICENSE=	gnu-gpl-v2

PATCH_SITES=	http://git.savannah.gnu.org/cgit/dmidecode.git/patch/?id=
DIST_SUBDIR=	dmidecode-patches
PATCHFILES=	ee07a1b4249560d620d05194eb8ff61b40d3ce23
PATCHFILES+=	174387405e98cd94c627832ae23abcb9be7e5623
PATCHFILES+=	2ba4fab210e23cc97db57217af9a6f3b35a9b666
PATCHFILES+=	8ff32018e8dd53c26d1f0daef118037fdae58c68
PATCHFILES+=	4cbba9a8e76ffc640eaf7dd25acbd3c1c6504669
PATCH_DIST_STRIP= -p1

MAKE_FLAGS+=	CFLAGS=${CFLAGS:Q}
MAKE_FLAGS+=	LDFLAGS=${LDFLAGS:Q}

ONLY_FOR_PLATFORM=	*-*-i386 *-*-x86_64

.include "../../mk/bsd.pkg.mk"
