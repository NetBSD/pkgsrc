# $NetBSD: Makefile,v 1.16 2001/08/14 17:13:02 abs Exp $
#

DISTNAME=		gtksql-0.3
CATEGORIES=		databases
MASTER_SITES=		http://www.multimania.com/bbrox/GtkSQL/ \
			${MASTER_SITE_SUNSITE:=X11/gtkbuffet/apps/gtksql/} \
			ftp://ftp.infodrom.north.de/pub/unix/gtkbuffet/apps/gtksql/ \
			ftp://ftp.loxinfo.co.th/pub/unix/database/

MAINTAINER=		packages@netbsd.org
HOMEPAGE=		http://www.multimania.com/bbrox/GtkSQL/
COMMENT=		Query tool for PostgreSQL written with GTK

DEPENDS+=		gtk+-1.2.*:../../x11/gtk
DEPENDS+=		postgresql-{6.5.3*,7.0*,lib-*}:../../databases/postgresql-lib

MAKE_ENV+=		X11PREFIX=${X11PREFIX}

USE_X11BASE=		# defined

USE_BUILDLINK_ONLY=	yes

.include "../../x11/gtk/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
