# $NetBSD: Makefile,v 1.76 2020/03/08 16:49:53 wiz Exp $

DISTNAME=	autotrace-0.31.1
PKGREVISION=	47
CATEGORIES=	graphics cad
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=autotrace/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://autotrace.sourceforge.net/
COMMENT=	Convert bitmap to vector graphics
LICENSE=	gnu-gpl-v2 AND gnu-lgpl-v2.1

GNU_CONFIGURE=		YES
USE_LIBTOOL=		YES

PKGCONFIG_OVERRIDE=	autotrace.pc.in

.include "../../graphics/ImageMagick/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
