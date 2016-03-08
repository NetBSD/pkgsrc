# $NetBSD: Makefile,v 1.21 2016/03/08 11:27:11 nros Exp $

DISTNAME=	libkcddb-15.12.0
PKGREVISION=	2
CATEGORIES=	multimedia
COMMENT=	KDE CDDB library
MASTER_SITES=	${MASTER_SITE_KDE:=applications/15.12.0/src/}

.include "../../meta-pkgs/kde4/Makefile.kde4"

.include "../../meta-pkgs/kde4/kde4.mk"

.include "../../audio/libmusicbrainz5/buildlink3.mk"
.include "../../x11/kdelibs4/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
