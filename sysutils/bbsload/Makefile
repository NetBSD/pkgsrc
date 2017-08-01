# $NetBSD: Makefile,v 1.19 2017/08/01 16:47:43 wiz Exp $
#

DISTNAME=	bbsload-0.2.6
PKGREVISION=	1
CATEGORIES=	sysutils x11 wm
#MASTER_SITES=	http://bbtools.windsofstorm.net/sources/

MAINTAINER=	pino@dohd.org
#HOMEPAGE=	http://bbtools.windsofstorm.net/
COMMENT=	Small (in dimensions) tool to display the average load

GNU_CONFIGURE=		YES
USE_LANGUAGES=		c c++

CPPFLAGS.NetBSD+=	-D_KERNTYPES

INSTALLATION_DIRS=	${PKGMANDIR}/man1

MAKE_ENV.DragonFly+=	LIBS.pkgsrc=-lkinfo

post-install:
	${INSTALL_MAN} ${WRKSRC}/bbsload.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/bbsload.1

BUILDLINK_DEPMETHOD.libXt?=	build

.include "../../x11/libSM/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
