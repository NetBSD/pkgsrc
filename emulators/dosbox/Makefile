# $NetBSD: Makefile,v 1.2 2003/07/21 16:45:54 martti Exp $
#

DISTNAME=	dosbox-0.58
CATEGORIES=	emulators
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=dosbox/}

MAINTAINER=	cube@cubidou.net
HOMEPAGE=	http://dosbox.sourceforge.net/
COMMENT=	Multi-platform DOS emulator using SDL

USE_BUILDLINK2=	YES
GNU_CONFIGURE=	YES

post-patch:
	${SED} -e s,/usr/share,${PREFIX}, ${WRKSRC}/docs/dosbox.1 > ${WRKSRC}/docs/dosbox.1.sed
	${MV} ${WRKSRC}/docs/dosbox.1.sed ${WRKSRC}/docs/dosbox.1

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/dosbox
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/dosbox

.include "../../devel/SDL/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
