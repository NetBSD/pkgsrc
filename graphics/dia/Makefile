# $NetBSD: Makefile,v 1.128 2024/05/29 16:32:50 adam Exp $

DISTNAME=	dia-0.97.3
PKGNAME=	${DISTNAME:S/dia-/dia${DIA_SUBPKG}-/}
PKGREVISION=	36
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/dia/0.97/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://live.gnome.org/Dia
COMMENT=	Program for creating diagrams of all kinds
LICENSE=	gnu-gpl-v2

# just to convert the manpage
TOOL_DEPENDS+=	docbook-xsl-[0-9]*:../../textproc/docbook-xsl

GNU_CONFIGURE=		YES
USE_TOOLS+=		gmake intltool pkg-config msgfmt
USE_LIBTOOL=		YES
USE_PKGLOCALEDIR=	YES
USE_LANGUAGES=		c c++

CHECK_PORTABILITY_SKIP+=	installer/macosx/dia

CONFIGURE_ARGS+=	--without-python

SUBST_CLASSES+=		intl
SUBST_MESSAGE.intl=	Fixing path to installed files.
SUBST_STAGE.intl=	pre-configure
SUBST_FILES.intl=	lib/intl.c
SUBST_VARS.intl=	PREFIX

SUBST_CLASSES+=		for
SUBST_MESSAGE.for=	Fixing empty "for" loops.
SUBST_STAGE.for=	pre-configure
SUBST_FILES.for=	doc/*/Makefile.in
SUBST_SED.for=		-e 's,for file in \$$(omffile); do,omffile="$$(omffile)"; for file in $$$$omffile; do,'

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/pango/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../graphics/libart/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../textproc/libxslt/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
