# $NetBSD: Makefile,v 1.7 2013/10/10 14:41:45 ryoon Exp $

DISTNAME=	pangox-compat-0.0.1
PKGREVISION=	6
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
