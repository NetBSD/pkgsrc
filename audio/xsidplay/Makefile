# $NetBSD: Makefile,v 1.20 2001/10/24 22:10:46 jlam Exp $
#

DISTNAME=	xsidplay-1_5_4
PKGNAME=	xsidplay-1.5.4
WRKSRC=		${WRKDIR}/xsidplay-1.5.4
CATEGORIES=	audio x11
MASTER_SITES=	http://www.geocities.com/SiliconValley/Lakes/5147/sidplay/packages/
EXTRACT_SUFX=	.tgz

MAINTAINER=	pooka@netbsd.org
HOMEPAGE=	http://www.geocities.com/SiliconValley/Lakes/5147/sidplay/
COMMENT=	Commodore 64 music player and SID chip emulator for X11

USE_BUILDLINK_ONLY=	yes
USE_LIBTOOL=		yes
LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig

USE_X11BASE=		yes
GNU_CONFIGURE=		yes
USE_GMAKE=		yes

CONFIGURE_ARGS+=	--with-qt-dir=${BUILDLINK_QTDIR}

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/src/xsidplay ${PREFIX}/bin

.include "../../audio/libsidplay/buildlink.mk"
.include "../../x11/qt2-libs/buildlink.mk"
.include "../../mk/x11.buildlink.mk"
.include "../../mk/bsd.pkg.mk"
