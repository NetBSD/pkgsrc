# $NetBSD: Makefile,v 1.17 2013/02/16 11:20:52 wiz Exp $

.include "../../meta-pkgs/xfce4/Makefile.common"

DISTNAME=	xfconf-${XFCE4_VERSION}
PKGREVISION=	15
CATEGORIES=	devel
COMMENT=	Xfce client-server configuration storage and query system

PKGCONFIG_OVERRIDE=	xfconf/libxfconf-0.pc.in

PERL5_CONFIGURE=	no
PERL5_PACKLIST=		auto/Xfce4/Xfconf/.packlist

CONFIGURE_ARGS+=	--with-perl-options=${MAKE_PARAMS}

MAKE_DIRS+=	${PREFIX}/include/xfce4

BUILDLINK_API_DEPENDS.dbus+=		dbus>=1.0.0
BUILDLINK_API_DEPENDS.dbus-glib+=	dbus-glib>=0.72

.include "../../devel/p5-glib2/buildlink3.mk"
.include "../../sysutils/dbus/buildlink3.mk"
.include "../../sysutils/dbus-glib/buildlink3.mk"
.include "../../x11/libxfce4util/buildlink3.mk"
.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
