# $NetBSD: Makefile,v 1.13 2009/03/16 09:12:25 jmcneill Exp $
#

DISTNAME=	orca-2.26.0
CATEGORIES=	misc
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/orca/2.26/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://live.gnome.org/Orca
COMMENT=	Screen reader

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	intltool pkg-config gmake msgfmt
USE_DIRS+=	xdg-1.1

PYTHON_VERSIONS_ACCEPTED= 25 24
CONFIGURE_ENV+=	PYTHON=${PYTHONBIN}
PY_PATCHPLIST=	yes

# The gettext version in pkgsrc cannot handle the .po files, so
# we strip out usage of the newer features (context and fuzzy matches)
post-patch:
	for f in ${WRKSRC}/po/*.po; do \
		mv $$f $$f.original ; \
		${AWK} -f ${FILESDIR}/msgfmtstrip $$f.original > $$f ; \
	done

BUILDLINK_API_DEPENDS.gnome-speech+=	gnome-speech>=0.3.10
.include "../../audio/gnome-speech/buildlink3.mk"
#BUILDLINK_API_DEPENDS.at-spi+=	at-spi>=1.7.6
.include "../../devel/py-at-spi/buildlink3.mk"
#BUILDLINK_API_DEPENDS.glib2+=	glib2>=2.10.0
.include "../../devel/glib2/buildlink3.mk"
#BUILDLINK_API_DEPENDS.libbonobo+=	libbonobo>=2.14.0
.include "../../devel/libbonobo/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../lang/python/extension.mk"
.include "../../net/ORBit2/buildlink3.mk"
.include "../../net/py-ORBit/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
BUILDLINK_API_DEPENDS.gnome-mag+=	gnome-mag>=0.12.5
.include "../../x11/gnome-mag/buildlink3.mk"
#BUILDLINK_API_DEPENDS.gtk2+=	gtk2+>=2.8.16
.include "../../x11/gtk2/buildlink3.mk"
.include "../../x11/py-gnome2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
