# $NetBSD: Makefile,v 1.15 2000/10/29 08:54:52 pooka Exp $
#

DISTNAME=	xsidplay-1_5_4
PKGNAME=	xsidplay-1.5.4
WRKSRC=		${WRKDIR}/xsidplay-1.5.4
CATEGORIES=	audio x11
MASTER_SITES=	http://www.geocities.com/SiliconValley/Lakes/5147/sidplay/packages/
EXTRACT_SUFX=	.tgz

MAINTAINER=	pooka@netbsd.org
HOMEPAGE=	http://www.geocities.com/SiliconValley/Lakes/5147/sidplay/

DEPENDS+=	sidplay>=1.0:../../audio/sidplay
DEPENDS+=	qt2>=2.2.1nb1:../../x11/qt2

USE_X11BASE=	yes
GNU_CONFIGURE=	yes
USE_GMAKE=	yes

EVAL_PREFIX+=	QT2DIR=qt2-libs
CONFIGURE_ARGS+= --with-sidplay-includes=${LOCALBASE}/include \
		--with-sidplay-library=${LOCALBASE}/lib \
		--with-qt-dir=${QT2DIR}/qt2

LDFLAGS+=	-Wl,-R${QT2DIR}/qt2/lib
CONFIGURE_ENV+=	LDFLAGS="${LDFLAGS}"

CONFIGURE_ENV+=	"MOC=${QT2DIR}/qt2/bin/moc"

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/src/xsidplay ${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
