# $NetBSD: Makefile,v 1.20 2018/02/01 04:08:44 msaitoh Exp $
#

DISTNAME=	dmidecode-3.1
PKGREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	http://download.savannah.gnu.org/releases/dmidecode/

MAINTAINER=	msaitoh@NetBSD.org
HOMEPAGE=	http://www.nongnu.org/dmidecode/
COMMENT=	Print out DMI (SMBIOS) table in human-readable format
LICENSE=	gnu-gpl-v2

PATCH_SITES=	http://git.savannah.gnu.org/cgit/dmidecode.git/patch/?id=
DIST_SUBDIR=	dmidecode-patches
PATCHFILES=	174387405e98cd94c627832ae23abcb9be7e5623
PATCH_DIST_STRIP= -p1

MAKE_FLAGS+=	CFLAGS=${CFLAGS:Q}
MAKE_FLAGS+=	LDFLAGS=${LDFLAGS:Q}

ONLY_FOR_PLATFORM=	*-*-i386 *-*-x86_64

.include "../../mk/bsd.pkg.mk"
