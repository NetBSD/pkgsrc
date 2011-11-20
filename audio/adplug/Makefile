# $NetBSD: Makefile,v 1.4 2011/11/20 01:26:58 marino Exp $
#

DISTNAME=	adplug-2.1
PKGREVISION=	1
CATEGORIES=	audio devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=adplug/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	jfranz@bsdprojects.net
HOMEPAGE=	http://adplug.sourceforge.net/
COMMENT=	AdLib emulator library supporting many formats

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config
USE_LANGUAGES=	c c++
INFO_FILES=	yes

PKGCONFIG_OVERRIDE+=	adplug.pc.in

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "DragonFly"
USE_TOOLS+=	perl
.endif

post-extract:
.if ${OPSYS} == "DragonFly"
	perl -i -pe "s/<string>/<strings.h>/" ${WRKSRC}/src/rol.h
	perl -i -pe "s/<string>/<string.h>/"  ${WRKSRC}/src/player.h
.endif

.include "../../devel/libbinio/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
