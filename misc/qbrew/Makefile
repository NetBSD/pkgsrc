# $NetBSD: Makefile,v 1.36 2023/01/29 21:17:13 ryoon Exp $

DISTNAME=	qbrew-0.4.1
PKGREVISION=	9
CATEGORIES=	misc
MASTER_SITES=	http://www.usermode.org/code/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.usermode.org/code.html
COMMENT=	Homebrewer's recipe calculator

USE_LANGUAGES=	c c++
USE_TOOLS+=	gmake
HAS_CONFIGURE=	yes
USE_LIBTOOL=	yes

BUILDLINK_DEPMETHOD.libXt?=	build

CONFIGURE_ARGS+=	--prefix=${DESTDIR}${PREFIX}
CONFIGURE_ARGS+=	--qtdir=${QTDIR}

.include "../../x11/libSM/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../x11/qt4-tools/buildlink3.mk"
.include "../../x11/qt4-libs/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
