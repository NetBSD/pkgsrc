# $NetBSD: Makefile,v 1.30 2018/08/16 18:55:05 adam Exp $

DISTNAME=	libkcddb-16.08.0
PKGREVISION=	6
CATEGORIES=	multimedia
COMMENT=	KDE CDDB library
MASTER_SITES=	${MASTER_SITE_KDE:=applications/16.08.0/src/}

.include "../../meta-pkgs/kde4/Makefile.kde4"

.include "../../meta-pkgs/kde4/kde4.mk"

.include "../../audio/libmusicbrainz5/buildlink3.mk"
.include "../../x11/kdelibs4/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
