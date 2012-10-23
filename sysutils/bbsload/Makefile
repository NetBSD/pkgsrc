# $NetBSD: Makefile,v 1.15 2012/10/23 19:50:52 asau Exp $
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
USE_X11BASE=		YES

INSTALLATION_DIRS=	${PKGMANDIR}/man1

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "DragonFly"
MAKE_ENV+=	LIBS.pkgsrc=-lkinfo
.endif

post-install:
	${INSTALL_MAN} ${WRKSRC}/bbsload.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/bbsload.1

BUILDLINK_DEPMETHOD.libXt?=	build

.include "../../x11/libSM/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
