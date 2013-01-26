# $NetBSD: Makefile,v 1.3 2013/01/26 21:36:40 adam Exp $
#

DISTNAME=	gupnp-vala-0.10.5
PKGREVISION=	1
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/gupnp-vala/0.10/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.gupnp.org/sources/bindings/
COMMENT=	Vala bindings for gupnp
LICENSE=	gnu-gpl-v2

GNU_CONFIGURE=	yes
USE_TOOLS+=	pkg-config gmake
USE_LANGUAGES=	c

PKGCONFIG_OVERRIDE+=	gupnp-vala-1.0.pc.in

.include "../../lang/vala018/buildlink3.mk"
BUILDLINK_API_DEPENDS.gssdp+= gssdp>=0.12.2.1nb2
.include "../../net/gssdp/buildlink3.mk"
.include "../../net/gupnp/buildlink3.mk"
.include "../../net/gupnp-av/buildlink3.mk"
.include "../../net/gupnp-dlna/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
