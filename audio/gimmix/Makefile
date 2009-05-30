# $NetBSD: Makefile,v 1.5 2009/05/30 01:33:11 obache Exp $
#

DISTNAME=	gimmix-0.5.6.1
CATEGORIES=	audio
MASTER_SITES=	http://download.berlios.de/gimmix/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://gimmix.berlios.de/
COMMENT=	Graphical Music player daemon (MPD) client

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_PKGLOCALEDIR=	yes
USE_TOOLS+=	intltool gmake msgfmt pkg-config
USE_DIRS+=	xdg-1.1

# fixes broken symbolic link to /usr/share/intltool/Makefile.in.in
post-extract:
	rm -f ${WRKSRC}/po/Makefile.in.in
	ln -s ${TOOLS_PREFIX.intltool:Q}/share/intltool/Makefile.in.in \
		${WRKSRC}/po/Makefile.in.in

.include "../../x11/gtk2/buildlink3.mk"
BUILDLINK_API_DEPENDS.libmpd+=		libmpd>=0.17.0
.include "../../audio/libmpd/buildlink3.mk"
BUILDLINK_API_DEPENDS.libglade+=	libglade>=2.6
.include "../../devel/libglade/buildlink3.mk"
BUILDLINK_API_DEPENDS.taglib+=		taglib>=1.4
.include "../../audio/taglib/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../textproc/libnxml/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
