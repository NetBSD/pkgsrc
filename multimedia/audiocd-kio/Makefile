# $NetBSD: Makefile,v 1.14 2014/08/22 11:24:39 wiz Exp $

DISTNAME=	audiocd-kio-${_KDE_VERSION}
PKGREVISION=	4
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
