# $NetBSD: Makefile,v 1.23 2018/10/12 10:08:00 msaitoh Exp $
#

DISTNAME=	dmidecode-3.2
EXTRACT_SUFX=	.tar.xz
CATEGORIES=	sysutils
MASTER_SITES=	http://download.savannah.gnu.org/releases/dmidecode/

MAINTAINER=	msaitoh@NetBSD.org
HOMEPAGE=	http://www.nongnu.org/dmidecode/
COMMENT=	Print out DMI (SMBIOS) table in human-readable format
LICENSE=	gnu-gpl-v2

MAKE_FLAGS+=	CFLAGS=${CFLAGS:Q}
MAKE_FLAGS+=	LDFLAGS=${LDFLAGS:Q}

ONLY_FOR_PLATFORM=	*-*-i386 *-*-x86_64

.include "../../mk/bsd.pkg.mk"
