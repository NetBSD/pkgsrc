# $NetBSD: Makefile,v 1.8 2005/07/21 16:29:56 wiz Exp $
#

DISTNAME=	libgnomecups-0.2.0
CATEGORIES=	print gnome
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/libgnomecups/0.2/}

MAINTAINER=	jmmv@NetBSD.org
HOMEPAGE=	http://www.gnome.org/
COMMENT=	GNOME interface to CUPS

GNU_CONFIGURE=		YES
USE_LIBTOOL=		YES

PKGCONFIG_OVERRIDE=	libgnomecups-1.0.pc.in

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/pkg-config/buildlink3.mk"
.include "../../print/cups/buildlink3.mk"
.include "../../textproc/intltool/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
