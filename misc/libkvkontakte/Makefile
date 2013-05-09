# $NetBSD: Makefile,v 1.13 2013/05/09 07:39:14 adam Exp $
#

PKGNAME=	libkvkontakte-3.1.0
DISTNAME=	digikam-3.1.0
PKGREVISION=	1
CATEGORIES=	misc
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=digikam/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.digikam.org/
COMMENT=	KDE library for asynchronous interaction with vkontakte.ru
LICENSE=	gnu-gpl-v2

BUILD_DEPENDS+=	automoc4>=0.9.83:../../devel/automoc4

USE_LANGUAGES=	c c++
USE_TOOLS+=	pkg-config

WRKSRC=		${WRKDIR}/${DISTNAME}/extra/libkvkontakte

.include "../../meta-pkgs/kde4/kde4.mk"
.include "../../devel/qjson/buildlink3.mk"
.include "../../x11/kdelibs4/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
