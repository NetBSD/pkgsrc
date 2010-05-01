# $NetBSD: Makefile,v 1.2 2010/05/01 20:52:36 wiz Exp $
#

DISTNAME=	jpegquality
PKGNAME=	jpegquality-20070802
CATEGORIES=	graphics
MASTER_SITES=	http://www.wired.com/images_blogs/threatlevel/files/
EXTRACT_SUFX=	.txt

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.wired.com/threatlevel/2007/08/researchers-ana/
COMMENT=	Print quantization tables of a JPEG file

PKG_DESTDIR_SUPPORT=	user-destdir
INSTALLATION_DIRS=	bin

DIST_SUBDIR=	${PKGNAME_NOREV}

WRKSRC=		${WRKDIR}
USE_LANGUAGES=	c # none

post-extract:
	mv ${WRKSRC}/jpegquality.txt ${WRKSRC}/jpegquality.c

do-build:
	cd ${WRKSRC} && ${CC} -o jpegquality jpegquality.c

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/jpegquality ${DESTDIR}${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
