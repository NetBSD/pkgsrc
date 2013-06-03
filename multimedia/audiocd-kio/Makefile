# $NetBSD: Makefile,v 1.4 2013/06/03 10:05:39 wiz Exp $

DISTNAME=	audiocd-kio-${_KDE_VERSION}
PKGREVISION=	1
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
