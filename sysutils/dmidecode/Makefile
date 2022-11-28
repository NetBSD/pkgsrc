# $NetBSD: Makefile,v 1.39 2022/11/28 04:26:08 mrg Exp $
#

DISTNAME=	dmidecode-3.4
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
