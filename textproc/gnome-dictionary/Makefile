# $NetBSD: Makefile,v 1.9 2022/08/11 05:09:19 gutteridge Exp $

DISTNAME=	gnome-dictionary-3.26.1
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/${PKGBASE}/${PKGVERSION_NOREV:R}/}
PKGREVISION=	2
CATEGORIES=	textproc gnome
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://wiki.gnome.org/Apps/Dictionary
COMMENT=	GNOME application to look up definitions
LICENSE=	gnu-gpl-v2

TOOL_DEPENDS+=	docbook-xsl-[0-9]*:../../textproc/docbook-xsl
TOOL_DEPENDS+=	libxslt-[0-9]*:../../textproc/libxslt

USE_TOOLS+=	pkg-config msgfmt xgettext itstool

PYTHON_FOR_BUILD_ONLY=	tool

LDFLAGS.SunOS+=	-lnsl

.include "../../devel/meson/build.mk"
.include "../../devel/gettext-tools/msgfmt-desktop.mk"
.include "../../devel/glib2/schemas.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../x11/gtk3/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
