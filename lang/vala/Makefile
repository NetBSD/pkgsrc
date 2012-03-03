# $NetBSD: Makefile,v 1.22 2012/03/03 00:12:11 wiz Exp $
#

DISTNAME=	vala-0.12.1
PKGREVISION=	3
CATEGORIES=	lang gnome
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/vala/0.12/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://live.gnome.org/Vala
COMMENT=	Compiler for the GObject type system
LICENSE=	gnu-lgpl-v2.1

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes
CONFIGURE_ARGS+= --enable-vapigen
CONFIGURE_ARGS+= --disable-unversioned
USE_LIBTOOL=	yes
USE_TOOLS+=		bison flex gmake pkg-config

PKGCONFIG_OVERRIDE+=	libvala.pc.in

BUILDLINK_API_DEPENDS.glib2+=	glib2>=2.16.0

.include "../../devel/glib2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
