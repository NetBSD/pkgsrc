# $NetBSD: Makefile,v 1.29 2004/10/03 00:13:12 tv Exp $
#

DISTNAME=	xsidplay-1.6.5.1a
PKGREVISION=	1
CATEGORIES=	audio x11
MASTER_SITES=	http://www.geocities.com/SiliconValley/Lakes/5147/sidplay/packages/
EXTRACT_SUFX=	.tgz

MAINTAINER=	pooka@NetBSD.org
HOMEPAGE=	http://www.geocities.com/SiliconValley/Lakes/5147/sidplay/
COMMENT=	Commodore 64 music player and SID chip emulator for X11

USE_BUILDLINK3=		yes
USE_LIBTOOL=		yes

GNU_CONFIGURE=		yes
USE_GNU_TOOLS+=		make
MAKE_ENV+=		MACHINE_ARCH=${MACHINE_ARCH}

CONFIGURE_ARGS+=	--with-qt-dir=${QTDIR}
CONFIGURE_ENV+=		DISABLE_ESD_TEST=yes
CONFIGURE_ENV+=		DISABLE_ARTSD_TEST=yes

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/src/xsidplay ${PREFIX}/bin

.include "../../audio/libsidplay/buildlink3.mk"
.include "../../x11/qt3-libs/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
