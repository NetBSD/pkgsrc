# $NetBSD: Makefile,v 1.17 2016/02/26 10:24:10 jperkin Exp $
#

DISTNAME=	bbsload-0.2.6
PKGREVISION=	1
CATEGORIES=	sysutils x11 wm
MASTER_SITES=	http://bbtools.windsofstorm.net/sources/

MAINTAINER=	pino@dohd.org
HOMEPAGE=	http://bbtools.windsofstorm.net/
COMMENT=	Small (in dimensions) tool to display the average load

GNU_CONFIGURE=		YES
USE_LANGUAGES=		c c++

INSTALLATION_DIRS=	${PKGMANDIR}/man1

MAKE_ENV.DragonFly+=	LIBS.pkgsrc=-lkinfo

post-install:
	${INSTALL_MAN} ${WRKSRC}/bbsload.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/bbsload.1

BUILDLINK_DEPMETHOD.libXt?=	build

.include "../../x11/libSM/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
