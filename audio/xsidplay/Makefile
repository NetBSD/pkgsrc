# $NetBSD: Makefile,v 1.6 2000/03/23 22:07:12 dmcmahill Exp $
#

DISTNAME=	xsidplay-1_3_8
PKGNAME=	xsidplay-1.3.8
WRKSRC=		${WRKDIR}/xsidplay-1.3.8
CATEGORIES=	audio x11
MASTER_SITES=	http://www.geocities.com/SiliconValley/Lakes/5147/sidplay/packages/
EXTRACT_SUFX=	_tar.gz

MAINTAINER=	pooka@iki.fi
HOMEPAGE=	http://www.geocities.com/SiliconValley/Lakes/5147/sidplay/

DEPENDS=	sidplay-1.36.35:../../audio/sidplay
DEPENDS+=	qt1-1.44:../../x11/qt1

USE_X11BASE=	yes
GNU_CONFIGURE=	yes
USE_GMAKE=	yes

CONFIGURE_ARGS+= --with-sidplay-includes=${LOCALBASE}/include \
		--with-sidplay-library=${LOCALBASE}/lib \
		--with-qt-includes=${LOCALBASE}/include/qt1 \
		--with-qt-libraries=${LOCALBASE}/lib \
		--with-qt-includes=${X11BASE}/include/qt1 \
		--with-qt-libraries=${X11BASE}/lib

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/src/xsidplay ${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
