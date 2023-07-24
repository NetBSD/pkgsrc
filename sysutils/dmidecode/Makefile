# $NetBSD: Makefile,v 1.40 2023/07/24 15:07:57 msaitoh Exp $
#

DISTNAME=	dmidecode-3.5
EXTRACT_SUFX=	.tar.xz
CATEGORIES=	sysutils
MASTER_SITES=	https://download.savannah.gnu.org/releases/dmidecode/
PKGREVISION=	1

MAINTAINER=	msaitoh@NetBSD.org
HOMEPAGE=	https://www.nongnu.org/dmidecode/
COMMENT=	Print out DMI (SMBIOS) table in human-readable format
LICENSE=	gnu-gpl-v2

MAKE_FLAGS+=	CFLAGS=${CFLAGS:Q}
MAKE_FLAGS+=	LDFLAGS=${LDFLAGS:Q}

ONLY_FOR_PLATFORM=	*-*-i386 *-*-x86_64 *-*-aarch64*

.include "../../mk/bsd.pkg.mk"
