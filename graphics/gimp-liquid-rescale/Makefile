# $NetBSD: Makefile,v 1.5 2008/04/05 02:11:48 tnn Exp $
#

DISTNAME=		gimp-lqr-plugin-0.4.0-4
PKGNAME=		gimp-liquid-rescale-0.4.0.4
CATEGORIES=		graphics
MASTER_SITES=		http://liquidrescale.wikidot.com/local--files/en:download-page/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://liquidrescale.wikidot.com/
COMMENT=		Content-aware image resizing plugin for the GIMP

USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes
USE_TOOLS+=		intltool msgfmt pkg-config gmake
PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=			${WRKDIR}/gimp-lqr-plugin-0.4.0
PTHREAD_AUTO_VARS=	yes

.include "../../graphics/gimp/buildlink3.mk"
.include "../../graphics/liblqr/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
