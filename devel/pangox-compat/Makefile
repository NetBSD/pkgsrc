# $NetBSD: Makefile,v 1.24 2023/11/14 14:01:40 wiz Exp $

DISTNAME=	pangox-compat-0.0.2
PKGREVISION=	14
CATEGORIES=	devel fonts
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/pangox-compat/${PKGVERSION_NOREV:R}/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.pango.org/
COMMENT=	Backwards compatibility library for pango X support
LICENSE=	gnu-lgpl-v2

USE_LIBTOOL=		yes
USE_LANGUAGES=		c c++
USE_TOOLS+=		gmake pkg-config
GNU_CONFIGURE=		yes

PKGCONFIG_OVERRIDE=	pangox.pc.in

.include "../../devel/pango/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
