# $NetBSD: Makefile,v 1.25 2019/08/11 13:18:38 wiz Exp $

DISTNAME=	atkmm-2.24.3
PKGREVISION=	1
CATEGORIES=	devel gnome
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/atkmm/${PKGVERSION_NOREV:R}/}
EXTRACT_SUFX=	.tar.xz
EXTRACT_USING=	bsdtar

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.gtkmm.org/
COMMENT=	C++ bindings for atk
LICENSE=	gnu-lgpl-v2.1 AND gnu-gpl-v2

CONFLICTS+=	gtkmm<2.22.0

USE_LANGUAGES=		c c++11
USE_LIBTOOL=		yes
USE_TOOLS+=		bsdtar gmake perl pkg-config
GNU_CONFIGURE=		yes
PKGCONFIG_OVERRIDE+=	atk/atkmm.pc.in

.include "../../devel/atk/buildlink3.mk"
.include "../../devel/glibmm/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
