# $NetBSD: Makefile,v 1.2 2007/03/24 19:08:51 wiz Exp $
#

DISTNAME=	makeppf3_src
PKGNAME=	makeppf-3.0
CATEGORIES=	emulators
MASTER_SITES=	# http://www.paradogs.com/download/
EXTRACT_SUFX=	.zip

MAINTAINER=	pkgsrc-users@NetBSD.org
#HOMEPAGE=	http://www.paradogs.com/pdx_ppf3.htm
COMMENT=	PPF (Playstation Patch File) v3.0 creation tool

WRKSRC=	${WRKDIR}

do-build:
	cd ${BUILD_DIRS} && ${CC} ${CPPFLAGS} ${CFLAGS} \
		-D_LARGEFILE_SOURCE -D_FILE_OFFSET_BITS=64 \
		-D_LARGEFILE64_SOURCE -o makeppf makeppf3_linux.c

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/makeppf ${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
