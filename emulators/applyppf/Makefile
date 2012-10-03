# $NetBSD: Makefile,v 1.4 2012/10/03 12:55:09 asau Exp $
#

DISTNAME=	applyppf3_src
PKGNAME=	applyppf-3.0
CATEGORIES=	emulators
MASTER_SITES=	# http://www.paradogs.com/download/
EXTRACT_SUFX=	.zip

MAINTAINER=	pkgsrc-users@NetBSD.org
#HOMEPAGE=	http://www.paradogs.com/pdx_ppf3.htm
COMMENT=	PPF (Playstation Patch File) v3.0 apply tool

WRKSRC=			${WRKDIR}
INSTALLATION_DIRS=	bin

do-build:
	cd ${BUILD_DIRS} && ${CC} ${CPPFLAGS} ${CFLAGS} \
		-D_LARGEFILE_SOURCE -D_FILE_OFFSET_BITS=64 \
		-D_LARGEFILE64_SOURCE -o applyppf applyppf3_linux.c

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/applyppf ${DESTDIR}${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
