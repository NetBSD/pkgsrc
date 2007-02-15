# $NetBSD: Makefile,v 1.13 2007/02/15 21:46:54 joerg Exp $
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

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "DragonFly"
MAKE_ENV+=	LIBS.pkgsrc=-lkinfo
.endif

post-install:
	${INSTALL_MAN} ${WRKSRC}/bbsload.1 ${PREFIX}/${PKGMANDIR}/man1/bbsload.1

BUILDLINK_DEPMETHOD.libXt?=	build

.include "../../x11/libSM/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
