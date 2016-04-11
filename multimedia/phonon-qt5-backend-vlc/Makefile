# $NetBSD: Makefile,v 1.3 2016/04/11 19:01:58 ryoon Exp $

DISTNAME=	phonon-backend-vlc-0.8.2
PKGNAME=	${DISTNAME:S/-/-qt5-/}
PKGREVISION=	2

COMMENT=	Multimedia API for KF5 - VLC backend

.include "../../multimedia/phonon-backend-vlc/Makefile.common"

CMAKE_ARGS+=	-DPHONON_BUILD_PHONON4QT5=ON

.include "../../multimedia/phonon-qt5/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
