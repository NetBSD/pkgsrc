# $NetBSD: Makefile,v 1.1 2021/02/20 21:41:08 ryoon Exp $

DISTNAME=	fcitx5-m17n-5.0.3
CATEGORIES=	inputmethod
MASTER_SITES=	https://download.fcitx-im.org/fcitx5/fcitx5-m17n/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	https://github.com/fcitx/fcitx5-m17n
COMMENT=	Wrapper library of m17n for Fcitx5
LICENSE=	gnu-lgpl-v2.1

USE_CMAKE=		yes
USE_PKGLOCALEDIR=	yes
USE_LANGUAGES=		c c++

.include "../../devel/m17n-lib/buildlink3.mk"
.include "../../inputmethod/fcitx5/buildlink3.mk"
.include "../../textproc/fmtlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
