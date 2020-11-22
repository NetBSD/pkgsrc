# $NetBSD: Makefile,v 1.22 2020/11/22 11:34:32 nia Exp $

DISTNAME=	libsecret-0.20.4
CATEGORIES=	security gnome
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/libsecret/${PKGVERSION_NOREV:R}/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	https://wiki.gnome.org/Projects/Libsecret
COMMENT=	GObject based library for accessing the Secret Service API
LICENSE=	gnu-lgpl-v2.1

TOOL_DEPENDS+=	libxslt-[0-9]*:../../textproc/libxslt
TOOL_DEPENDS+=	docbook-xsl-[0-9]*:../../textproc/docbook-xsl
TOOL_DEPENDS+=	gdbus-codegen-[0-9]*:../../devel/gdbus-codegen

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	gmake pkg-config gsed
USE_TOOLS+=	msgfmt msgmerge xgettext

PKGCONFIG_OVERRIDE+=	libsecret/libsecret-unstable.pc.in
PKGCONFIG_OVERRIDE+=	libsecret/libsecret.pc.in

BUILDLINK_API_DEPENDS.glib2+=	glib2>=2.44.0
.include "../../devel/glib2/buildlink3.mk"
.include "../../lang/vala/buildlink3.mk"
.include "../../security/libgcrypt/buildlink3.mk"
.include "options.mk"
.include "../../mk/bsd.pkg.mk"
