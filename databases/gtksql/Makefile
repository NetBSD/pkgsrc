# $NetBSD: Makefile,v 1.31 2004/10/03 00:13:18 tv Exp $
#

DISTNAME=		gtksql-0.3
PKGREVISION=		5
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

PGSQL_VERSION_REQD=	73

.include "../../mk/pgsql.buildlink3.mk"
.include "../../x11/gtk/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
