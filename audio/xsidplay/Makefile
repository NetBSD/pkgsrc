# $NetBSD: Makefile,v 1.11 2000/07/11 14:53:37 agc Exp $
#

DISTNAME=	xsidplay-1_3_9
PKGNAME=	xsidplay-1.3.9
WRKSRC=		${WRKDIR}/xsidplay-1.3.9
CATEGORIES=	audio x11
MASTER_SITES=	http://www.geocities.com/SiliconValley/Lakes/5147/sidplay/packages/
EXTRACT_SUFX=	.tgz

MAINTAINER=	pooka@netbsd.org
HOMEPAGE=	http://www.geocities.com/SiliconValley/Lakes/5147/sidplay/

DEPENDS+=	sidplay-1.0.*:../../audio/sidplay
DEPENDS+=	qt1-1.44:../../x11/qt1

USE_X11BASE=	yes
GNU_CONFIGURE=	yes
USE_GMAKE=	yes

CONFIGURE_ARGS+= --with-sidplay-includes=${LOCALBASE}/include \
		--with-sidplay-library=${LOCALBASE}/lib \
		--with-qt-dir=`${MAKE} show-qt1-prefix`/qt1/lib

LDFLAGS+=	-Wl,-R`${MAKE} show-qt1-prefix`/qt1/lib
CONFIGURE_ENV+=	LDFLAGS="${LDFLAGS}"

CONFIGURE_ENV+=	"MOC=`${MAKE} show-qt1-prefix`/qt1/bin/moc"

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/src/xsidplay ${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
