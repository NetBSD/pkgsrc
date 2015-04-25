# $NetBSD: Makefile,v 1.18 2015/04/25 14:23:37 tnn Exp $

DISTNAME=	audiocd-kio-${_KDE_VERSION}
PKGREVISION=	2
CATEGORIES=	multimedia
COMMENT=	Kioslave for accessing audio CDs

.include "../../meta-pkgs/kde4/Makefile.kde4"

.include "../../meta-pkgs/kde4/kde4.mk"

.include "../../audio/cdparanoia/buildlink3.mk"
.include "../../audio/flac/buildlink3.mk"
.include "../../audio/libvorbis/buildlink3.mk"
.include "../../multimedia/libkcddb/buildlink3.mk"
.include "../../multimedia/libkcompactdisc/buildlink3.mk"
.include "../../x11/kdelibs4/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
