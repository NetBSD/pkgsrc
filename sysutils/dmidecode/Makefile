# $NetBSD: Makefile,v 1.16 2016/04/18 15:29:38 khorben Exp $
#

DISTNAME=	dmidecode-2.12
CATEGORIES=	sysutils
MASTER_SITES=	http://savannah.gnu.org/download/dmidecode/

MAINTAINER=	shattered@NetBSD.org
HOMEPAGE=	http://www.nongnu.org/dmidecode/
COMMENT=	Print out DMI (SMBIOS) table in human-readable format
LICENSE=	gnu-gpl-v2

MAKE_FLAGS+=	CFLAGS=${CFLAGS:Q}
MAKE_FLAGS+=	LDFLAGS=${LDFLAGS:Q}

ONLY_FOR_PLATFORM=	*-*-i386 *-*-x86_64

.include "../../mk/bsd.pkg.mk"
