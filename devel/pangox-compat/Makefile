# $NetBSD: Makefile,v 1.6 2013/09/02 19:50:51 adam Exp $

DISTNAME=	pangox-compat-0.0.1
PKGREVISION=	5
CATEGORIES=	devel fonts
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/pangox-compat/${PKGVERSION_NOREV:R}/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.pango.org/
COMMENT=	Backwards compatibility library for pango X support
LICENSE=	gnu-lgpl-v2

USE_LIBTOOL=		yes
USE_LANGUAGES=		c c++
USE_TOOLS+=		gmake pkg-config
GNU_CONFIGURE=		yes

PKGCONFIG_OVERRIDE=	pangox.pc.in

.include "../../devel/pango/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
