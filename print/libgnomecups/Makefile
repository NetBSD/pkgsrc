# $NetBSD: Makefile,v 1.5 2005/02/27 12:52:56 jmmv Exp $
#

DISTNAME=	libgnomecups-0.1.14
CATEGORIES=	print gnome
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/libgnomecups/0.1/}

MAINTAINER=	jmmv@NetBSD.org
HOMEPAGE=	http://www.gnome.org/
COMMENT=	GNOME interface to CUPS

GNU_CONFIGURE=		YES
USE_BUILDLINK3=		YES
USE_LIBTOOL=		YES

PKGCONFIG_OVERRIDE=	libgnomecups-1.0.pc.in

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/pkgconfig/buildlink3.mk"
.include "../../print/cups/buildlink3.mk"
.include "../../textproc/intltool/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
