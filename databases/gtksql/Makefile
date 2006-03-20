# $NetBSD: Makefile,v 1.37 2006/03/20 19:49:16 joerg Exp $
#

DISTNAME=		gtksql-0.3
PKGREVISION=		6
CATEGORIES=		databases
MASTER_SITES=		http://www.multimania.com/bbrox/GtkSQL/ \
			${MASTER_SITE_SUNSITE:=X11/gtkbuffet/apps/gtksql/} \
			ftp://ftp.infodrom.north.de/pub/unix/gtkbuffet/apps/gtksql/ \
			ftp://ftp.loxinfo.co.th/pub/unix/database/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.multimania.com/bbrox/GtkSQL/
COMMENT=		Query tool for PostgreSQL written with GTK

USE_X11BASE=		yes
MAKE_ENV+=		MCFLAGS=${CFLAGS:M*:Q}

.include "../../mk/pgsql.buildlink3.mk"
.include "../../x11/gtk/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
