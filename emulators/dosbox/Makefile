# $NetBSD: Makefile,v 1.4 2003/11/10 00:13:22 xtraeme Exp $
#

DISTNAME=	dosbox-0.60
CATEGORIES=	emulators
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=dosbox/}

MAINTAINER=	cube@cubidou.net
HOMEPAGE=	http://dosbox.sourceforge.net/
COMMENT=	Multi-platform DOS emulator using SDL

USE_BUILDLINK2=	YES
GNU_CONFIGURE=	YES

post-patch:
	${SED} -e s,/usr/share,${PREFIX}/share, \
		${WRKSRC}/docs/dosbox.1 > ${WRKSRC}/docs/dosbox.1.sed
	${MV} ${WRKSRC}/docs/dosbox.1.sed ${WRKSRC}/docs/dosbox.1

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/dosbox
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/dosbox

.include "../../devel/SDL/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
