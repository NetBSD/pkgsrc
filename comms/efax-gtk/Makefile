# $NetBSD: Makefile,v 1.69 2014/05/05 00:47:41 ryoon Exp $

DISTNAME=	efax-gtk-3.2.3.src
PKGNAME=	efax-gtk-3.2.3
PKGREVISION=	20
CATEGORIES=	comms
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=efax-gtk/}
EXTRACT_SUFX=	.tgz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://efax-gtk.sourceforge.net/
COMMENT=	GTK frontend for efax

WRKSRC=			${WRKDIR}/${PKGNAME_NOREV}
USE_LANGUAGES=		c c++
USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		pkg-config
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR}
CONFIGURE_ARGS+=	--with-spooldir=${VARBASE}/spool/efax
LDFLAGS.DragonFly=	-lX11
LDFLAGS.SunOS+=		-lX11 -lsocket -lnsl

EGDIR=			${PREFIX}/share/examples
CONF_FILES=		${EGDIR}/efax-gtkrc ${PKG_SYSCONFDIR}/efax-gtkrc

SUBST_CLASSES+=		xopen
SUBST_MESSAGE.xopen=	Removing _XOPEN_SOURCE=600 definition
SUBST_STAGE.xopen=	post-patch
SUBST_FILES.xopen=	src/Makefile.in src/utils/Makefile.in
SUBST_FILES.xopen+=	src/internal/c++-gtk-utils/Makefile.in
SUBST_SED.xopen=	-e 's,-D_XOPEN_SOURCE=600,,'

.include "../../converters/libiconv/buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"
.include "../../sysutils/dbus-glib/buildlink3.mk"
.include "../../x11/gtkmm/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/bsd.pkg.mk"
