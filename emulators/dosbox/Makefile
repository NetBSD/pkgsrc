# $NetBSD: Makefile,v 1.6 2004/03/07 06:04:48 snj Exp $
#

DISTNAME=	dosbox-0.61
CATEGORIES=	emulators
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=dosbox/}

MAINTAINER=	cube@cubidou.net
HOMEPAGE=	http://dosbox.sourceforge.net/
COMMENT=	Multi-platform DOS emulator using SDL

USE_BUILDLINK3=	YES
GNU_CONFIGURE=	YES

SUBST_CLASSES=		fixme
SUBST_STAGE.fixme=	post-patch
SUBST_FILES.fixme=	docs/dosbox.1
SUBST_SED.fixme=	-e s,/usr/share/,${PREFIX}/share/,g

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/dosbox
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/dosbox

.include "../../devel/SDL/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../net/SDL_net/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
