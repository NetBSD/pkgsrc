# $NetBSD: Makefile,v 1.20 2009/04/07 11:12:27 drochner Exp $
#

DISTNAME=	libgnomecups-0.2.3
CATEGORIES=	print gnome
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/libgnomecups/0.2/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.gnome.org/
COMMENT=	GNOME interface to CUPS

PKG_DESTDIR_SUPPORT=	user-destdir

USE_TOOLS+=		intltool msgfmt pkg-config gmake
GNU_CONFIGURE=		YES
USE_LIBTOOL=		YES
USE_PKGLOCALEDIR=	YES

PKGCONFIG_OVERRIDE=	libgnomecups-1.0.pc.in

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../print/cups/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
