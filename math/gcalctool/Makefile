# $NetBSD: Makefile,v 1.78 2009/03/18 00:32:45 jmcneill Exp $
#

DISTNAME=		gcalctool-5.26.0
CATEGORIES=		math gnome
MASTER_SITES=		${MASTER_SITE_GNOME:=sources/gcalctool/5.26/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://calctool.sourceforge.net/
COMMENT=		Desktop calculator for GNOME

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=		YES
CONFIGURE_ENV+=		HAVE_YACC=yes

USE_DIRS+=		gnome2-1.5
USE_LIBTOOL=		yes
USE_TOOLS+=		bison gmake intltool flex msgfmt pkg-config
USE_PKGLOCALEDIR=	yes

GCONF_SCHEMAS=		gcalctool.schemas

# The gettext version in pkgsrc cannot handle the .po files, so
# we strip out usage of the newer features (context and fuzzy matches)
post-patch:
	for f in ${WRKSRC}/po/*.po ${WRKSRC}/help/*/*.po ; do \
		mv $$f $$f.original ; \
		${AWK} -f ${FILESDIR}/msgfmtstrip $$f.original > $$f ; \
	done

BUILDLINK_API_DEPENDS.gtk2+=	gtk2+>=2.6.0

.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../devel/GConf/schemas.mk"
.include "../../devel/atk/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/libgnome/buildlink3.mk"
.include "../../devel/libgnomeui/buildlink3.mk"
.include "../../textproc/gnome-doc-utils/buildlink3.mk"
.include "../../mk/omf-scrollkeeper.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
