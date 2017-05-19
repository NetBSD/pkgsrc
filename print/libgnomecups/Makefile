# $NetBSD: Makefile,v 1.40 2017/05/19 13:29:04 prlw1 Exp $
#

DISTNAME=	libgnomecups-0.2.3
PKGREVISION=	17
CATEGORIES=	print gnome
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/libgnomecups/0.2/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.gnome.org/
COMMENT=	GNOME interface to CUPS

USE_TOOLS+=		intltool msgfmt pkg-config gmake
GNU_CONFIGURE=		YES
USE_LIBTOOL=		YES
USE_PKGLOCALEDIR=	YES

PKGCONFIG_OVERRIDE=	libgnomecups-1.0.pc.in

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../print/cups/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
