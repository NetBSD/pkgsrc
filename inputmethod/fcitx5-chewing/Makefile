# $NetBSD: Makefile,v 1.2 2021/02/27 20:05:21 ryoon Exp $

DISTNAME=	fcitx5-chewing-5.0.4
CATEGORIES=	inputmethod
MASTER_SITES=	https://download.fcitx-im.org/fcitx5/fcitx5-chewing/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	https://github.com/fcitx/fcitx5-chewing
COMMENT=	Chewing engine for Fcitx5
LICENSE=	gnu-gpl-v2

USE_CMAKE=		yes
USE_PKGLOCALEDIR=	yes
USE_LANGUAGES=		c c++

.include "../../inputmethod/fcitx5/buildlink3.mk"
.include "../../inputmethod/libchewing/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
