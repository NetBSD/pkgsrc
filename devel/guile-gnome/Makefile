# $NetBSD: Makefile,v 1.3 2006/09/20 19:54:51 joerg Exp $

DISTNAME=	guile-gnome-platform-2.7.99
PKGREVISION=	2
CATEGORIES=	devel
MASTER_SITES=	http://ftp.gnu.org/gnu/guile-gnome/guile-gnome-platform/

MAINTAINER=	gdt@NetBSD.org
HOMEPAGE=	http://www.gnu.org/software/guile-gnome/
COMMENT=	Library to access gobject/glib/gtk and gnome from guile

DEPENDS+=	guile-slib>=2.4.2:../../devel/guile-slib

GNU_CONFIGURE=		YES
USE_TOOLS+=		gmake makeinfo pkg-config
USE_LIBTOOL=		YES
INFO_FILES=		# PLIST

.include "../../devel/g-wrap/buildlink3.mk"
# XXX split into separate packages
.include "../../devel/libgnomeui/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
