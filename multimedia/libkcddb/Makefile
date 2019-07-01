# $NetBSD: Makefile,v 1.32 2019/07/01 04:08:38 ryoon Exp $

DISTNAME=	libkcddb-16.08.0
PKGREVISION=	8
CATEGORIES=	multimedia
COMMENT=	KDE CDDB library
MASTER_SITES=	${MASTER_SITE_KDE:=applications/16.08.0/src/}

.include "../../meta-pkgs/kde4/Makefile.kde4"

.include "../../meta-pkgs/kde4/kde4.mk"

.include "../../audio/libmusicbrainz5/buildlink3.mk"
.include "../../x11/kdelibs4/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
