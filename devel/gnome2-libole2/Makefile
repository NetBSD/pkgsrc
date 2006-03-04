# $NetBSD: Makefile,v 1.16 2006/03/04 21:29:15 jlam Exp $
#

DISTNAME=		libole2-2.2.8
PKGNAME=		gnome2-${DISTNAME}
PKGREVISION=		5
CATEGORIES=		devel gnome
MASTER_SITES=		${MASTER_SITE_GNOME:=sources/libole2/2.2/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.gnome.org/
COMMENT=		OLE2 streams parsing library for GNOME2

BUILD_USES_MSGFMT=	YES

GNU_CONFIGURE=		YES
USE_LIBTOOL=		YES
USE_TOOLS+=		pkg-config

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../mk/x11.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
