# $NetBSD: Makefile,v 1.33 2019/08/22 12:23:37 ryoon Exp $

DISTNAME=	libkcddb-16.08.0
PKGREVISION=	9
CATEGORIES=	multimedia
COMMENT=	KDE CDDB library
MASTER_SITES=	${MASTER_SITE_KDE:=applications/16.08.0/src/}

.include "../../meta-pkgs/kde4/Makefile.kde4"

.include "../../meta-pkgs/kde4/kde4.mk"

.include "../../audio/libmusicbrainz5/buildlink3.mk"
.include "../../x11/kdelibs4/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
