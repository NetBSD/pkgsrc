# $NetBSD: Makefile,v 1.49 2016/09/15 14:32:39 wiz Exp $
#

DISTNAME=		guile-gtk-0.60
PKGREVISION=		13
CATEGORIES=		devel x11
MASTER_SITES=		${MASTER_SITE_GNU:=guile-gtk/}

MAINTAINER=		gdt@NetBSD.org
HOMEPAGE=		http://www.gnu.org/software/guile-gtk/
COMMENT=		Library to make GTK 1.2 accessible from guile

USE_LIBTOOL=		yes
USE_TOOLS+=		makeinfo

GNU_CONFIGURE=		yes
MAKE_ENV+=		MACHINE_ARCH=${MACHINE_ARCH:Q}
INFO_FILES=		yes

.include "../../lang/guile/buildlink3.mk"
.include "../../x11/gtk/buildlink3.mk"
.include "../../graphics/gdk-pixbuf/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
