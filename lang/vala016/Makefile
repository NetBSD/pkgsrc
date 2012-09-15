# $NetBSD: Makefile,v 1.4 2012/09/15 10:05:22 obache Exp $
#

DISTNAME=	vala-0.16.1
PKGNAME=	vala016-0.16.1
PKGREVISION=	1
CATEGORIES=	lang gnome
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/vala/0.16/}
EXTRACT_SUFX=	.tar.xz

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
BUILDLINK_DEPMETHOD.libxslt=			build

.include "../../devel/glib2/buildlink3.mk"
.include "../../textproc/libxslt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
