# $NetBSD: Makefile,v 1.5 2004/02/03 17:48:11 xtraeme Exp $
#

DISTNAME=	dosbox-0.61
CATEGORIES=	emulators
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=dosbox/}

MAINTAINER=	cube@cubidou.net
HOMEPAGE=	http://dosbox.sourceforge.net/
COMMENT=	Multi-platform DOS emulator using SDL

USE_BUILDLINK2=	YES
GNU_CONFIGURE=	YES

SUBST_CLASSES=		fixme
SUBST_STAGE.fixme=	post-patch
SUBST_FILES.fixme=	docs/dosbox.1
SUBST_SED.fixme=	-e s,/usr/share/,${PREFIX}/share/,g

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/dosbox
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/dosbox

.include "../../devel/SDL/buildlink2.mk"
.include "../../graphics/png/buildlink2.mk"
.include "../../net/SDL_net/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
