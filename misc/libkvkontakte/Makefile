# $NetBSD: Makefile,v 1.51 2020/11/05 09:07:01 ryoon Exp $

DISTNAME=	libkvkontakte-5.0.0
PKGREVISION=	8
CATEGORIES=	misc
MASTER_SITES=	${MASTER_SITE_KDE:=libkvkontakte/5.0.0/src/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.digikam.org/
COMMENT=	KDE library for asynchronous interaction with vkontakte.ru
LICENSE=	gnu-gpl-v2

.include "../../meta-pkgs/kde/applications.mk"

USE_TOOLS+=	msgmerge pkg-config

.include "../../www/kdewebkit/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
