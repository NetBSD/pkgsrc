# $NetBSD: Makefile,v 1.110 2022/06/28 11:34:01 wiz Exp $

DISTNAME=		gnome-icon-theme-3.12.0
PKGREVISION=		8
CATEGORIES=		graphics gnome
MASTER_SITES=		${MASTER_SITE_GNOME:=sources/gnome-icon-theme/${PKGVERSION_NOREV:R}/}
EXTRACT_SUFX=		.tar.xz

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://www.gnome.org/
COMMENT=		Theme consisting of a set of icons for GNOME
LICENSE=		cc-by-sa-v3.0 AND gnu-lgpl-v3

GNU_CONFIGURE=		yes
USE_TOOLS+=		gmake intltool msgfmt pkg-config
# otherwise it creates lots of lib/locale dirs, even though it doesn't
# need them (!)
USE_PKGLOCALEDIR=	yes
TOOLS_NOOP+=		gtk-update-icon-cache

PKGCONFIG_OVERRIDE=	gnome-icon-theme.pc.in

# The list of installed files depends on the version of
# icon-naming-utils, so be sure that this dependency corresponds to
# the current pkgsrc version.
BUILDLINK_API_DEPENDS.icon-naming-utils+=	icon-naming-utils>=0.8.90

ICON_THEMES=	yes

.include "../../mk/bsd.prefs.mk"
post-install:
.if ${OPSYS} == "NetBSD"
.  for s in 16 22 24 32 48 256
	${INSTALL_DATA} ${FILESDIR}/netbsd-${s}.png ${DESTDIR}${PREFIX}/share/icons/gnome/${s}x${s}/places/start-here.png
.  endfor
.endif

BUILDLINK_DEPMETHOD.gettext-lib=	build
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../graphics/icon-naming-utils/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
