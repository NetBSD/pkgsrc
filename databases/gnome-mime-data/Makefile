# $NetBSD: Makefile,v 1.35 2007/04/15 10:36:19 wiz Exp $
#

DISTNAME=		gnome-mime-data-2.18.0
CATEGORIES=		databases gnome
MASTER_SITES=		${MASTER_SITE_GNOME:=sources/gnome-mime-data/2.18/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.gnome.org/
COMMENT=		MIME and Application database for GNOME2

PKG_INSTALLATION_TYPES=	overwrite pkgviews

CONFLICTS=		gnome-vfs<=1.0.3

USE_DIRS+=		gnome2-1.5
USE_PKGLOCALEDIR=	YES
USE_TOOLS+=		intltool msgfmt perl gmake
GNU_CONFIGURE=		YES

PKGCONFIG_OVERRIDE=	gnome-mime-data-2.0.pc.in

CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR:Q}

EGDIR=			${PREFIX}/share/examples/gnome-mime-data
CONF_FILES=		${EGDIR}/gnome-vfs-mime-magic \
				${PKG_SYSCONFDIR}/gnome-vfs-mime-magic

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
