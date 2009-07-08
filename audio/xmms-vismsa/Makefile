# $NetBSD: Makefile,v 1.19 2009/07/08 14:25:32 joerg Exp $
#

DISTNAME=	vismsa-xmms-plugin-0.2
PKGNAME=	xmms-vismsa-0.2
PKGREVISION=	4
CATEGORIES=	audio
MASTER_SITES=	# http://a.godau.org/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://a.godau.org/
COMMENT=	Vis plugin similar to the Spectrum Analyser from Open Cubic Player

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LIBTOOL=		YES

INSTALLATION_DIRS=	lib/xmms/Visualization

pre-build:
	cd ${WRKSRC} ; ${MAKE} clean

.include "../../audio/xmms/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
