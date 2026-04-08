# $NetBSD: Makefile,v 1.6 2026/04/08 12:32:20 wiz Exp $

DISTNAME=	libdsk-1.3.8
CATEGORIES=	emulators
MASTER_SITES=	https://www.seasip.info/Unix/LibDsk/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.seasip.info/Unix/LibDsk/
COMMENT=	Library for accessing floppy discs and disc image files
LICENSE=	gnu-gpl-v2

GNU_CONFIGURE=	yes
USE_LANGUAGES=	c
USE_LIBTOOL=	yes

CFLAGS+=	-Wno-implicit-function-declaration

.include "../../mk/bsd.pkg.mk"
