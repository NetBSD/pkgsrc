# $NetBSD: Makefile,v 1.29 2004/07/24 22:45:14 recht Exp $
#

DISTNAME=		gtksql-0.3
PKGREVISION=		4
CATEGORIES=		databases
MASTER_SITES=		http://www.multimania.com/bbrox/GtkSQL/ \
			${MASTER_SITE_SUNSITE:=X11/gtkbuffet/apps/gtksql/} \
			ftp://ftp.infodrom.north.de/pub/unix/gtkbuffet/apps/gtksql/ \
			ftp://ftp.loxinfo.co.th/pub/unix/database/

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://www.multimania.com/bbrox/GtkSQL/
COMMENT=		Query tool for PostgreSQL written with GTK

USE_BUILDLINK3=		yes
USE_X11BASE=		# defined
MAKE_ENV+=		MCFLAGS="${CFLAGS}"

.include "../../mk/pgsql.buildlink3.mk"
.include "../../x11/gtk/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
