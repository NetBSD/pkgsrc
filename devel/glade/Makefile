# $NetBSD: Makefile,v 1.91 2018/11/12 03:51:52 ryoon Exp $

DISTNAME=	glade-2.12.2
PKGREVISION=	29
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/glade/2.12/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://glade.gnome.org/
COMMENT=	User interface builder for the GTK2+ toolkit
LICENSE=	gnu-gpl-v2

CONFLICTS+=		glade2-[0-9]* glade2-gnome-[0-9]*
CONFLICTS+=		glade-gnome-[0-9]*

GNU_CONFIGURE=		YES
USE_TOOLS+=		gmake intltool msgfmt pkg-config
USE_LIBTOOL=		YES
USE_PKGLOCALEDIR=	YES

CONFIGURE_ARGS+=	--disable-gnome
CONFIGURE_ARGS+=	--disable-gnome-db

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../mk/omf-scrollkeeper.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/bsd.pkg.mk"
