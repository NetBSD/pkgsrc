# $NetBSD: Makefile,v 1.15 2019/02/13 19:52:08 wiz Exp $

DISTNAME=	libsecret-0.18.7
CATEGORIES=	security gnome
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/libsecret/0.18/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	https://wiki.gnome.org/Projects/Libsecret
COMMENT=	GObject based library for accessing the Secret Service API
LICENSE=	gnu-lgpl-v2.1

BUILD_DEPENDS+=	libxslt-[0-9]*:../../textproc/libxslt
BUILD_DEPENDS+=	docbook-xsl-[0-9]*:../../textproc/docbook-xsl
TOOL_DEPENDS+=	gdbus-codegen-[0-9]*:../../devel/gdbus-codegen

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	gmake intltool pkg-config msgfmt gsed

PKGCONFIG_OVERRIDE+=	libsecret/libsecret-unstable.pc.in
PKGCONFIG_OVERRIDE+=	libsecret/libsecret.pc.in

BUILDLINK_API_DEPENDS.glib2+=	glib2>=2.38.0
.include "../../devel/glib2/buildlink3.mk"
.include "../../security/libgcrypt/buildlink3.mk"
.include "options.mk"
.include "../../mk/bsd.pkg.mk"
