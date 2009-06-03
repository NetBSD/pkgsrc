# $NetBSD: Makefile,v 1.68 2009/06/03 12:40:32 obache Exp $
#

DISTNAME=		atk-1.26.0
CATEGORIES=		devel
MASTER_SITES=		${MASTER_SITE_GNOME:=sources/atk/1.26/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://developer.gnome.org/projects/gap/
COMMENT=		Set of interfaces for accessibility

PKG_INSTALLATION_TYPES=	overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir

USE_TOOLS+=		gmake pkg-config msgfmt
GNU_CONFIGURE=		yes
USE_PKGLOCALEDIR=	yes
USE_LANGUAGES+=		c99
USE_LIBTOOL=		yes
PKGCONFIG_OVERRIDE=	atk.pc.in

# glib-mkenums overflows a 2048kb stack on atkobject.h
UNLIMIT_RESOURCES=	stacksize

SUBST_CLASSES+=		loc
SUBST_STAGE.loc=	pre-configure
SUBST_MESSAGE.loc=	Fixing invalid use of AM_GLIB_DEFINE_LOCALEDIR.
SUBST_FILES.loc=	configure
SUBST_SED.loc=		-e 's,^\(\#define ATK_LOCALEDIR\).*,\1 "${PREFIX}/${PKGLOCALEDIR}/locale",'

# Workaround for Upstream Bug#562310.
# for more detail, see also PR#41475.
TOOLS_NOOP+=	gtkdoc-rebase

.include "../../devel/gettext-lib/buildlink3.mk"
BUILDLINK_API_DEPENDS.glib2+=	glib2>=2.5.7
.include "../../devel/glib2/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
