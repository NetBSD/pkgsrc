# $NetBSD: Makefile,v 1.22.2.1 2003/03/15 12:23:10 grant Exp $
#

DISTNAME=	xsidplay-1_5_4
PKGNAME=	xsidplay-1.5.4
PKGREVISION=	1
WRKSRC=		${WRKDIR}/xsidplay-1.5.4
CATEGORIES=	audio x11
MASTER_SITES=	http://www.geocities.com/SiliconValley/Lakes/5147/sidplay/packages/
EXTRACT_SUFX=	.tgz

MAINTAINER=	pooka@netbsd.org
HOMEPAGE=	http://www.geocities.com/SiliconValley/Lakes/5147/sidplay/
COMMENT=	Commodore 64 music player and SID chip emulator for X11

USE_BUILDLINK2=		yes
USE_LIBTOOL=		yes
LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig

USE_X11BASE=		yes
GNU_CONFIGURE=		yes
USE_GMAKE=		yes
MAKE_ENV+=		MACHINE_ARCH=${MACHINE_ARCH}

CONFIGURE_ARGS+=	--with-qt-dir=${QTDIR}

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/src/xsidplay ${PREFIX}/bin

.include "../../audio/libsidplay/buildlink2.mk"
.include "../../x11/qt2-libs/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
