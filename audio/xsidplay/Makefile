# $NetBSD: Makefile,v 1.9 2000/07/10 15:08:14 agc Exp $
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
		--with-qt-dir=`${PKG_INFO} -qp qt1 | ${AWK} '{ print $$2 }'`/qt1/lib \
		--with-qt-dir=${X11BASE}/qt1

LDFLAGS+=	-Wl,-R${LOCALBASE}/qt1/lib -Wl,-R${X11BASE}/qt1/lib
CONFIGURE_ENV+=	LDFLAGS="${LDFLAGS}"

CONFIGURE_ENV+=	"MOC=`${PKG_INFO} -qp qt1 | ${AWK} '{ print $$2 }'`/qt1/bin/moc"

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/src/xsidplay ${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
