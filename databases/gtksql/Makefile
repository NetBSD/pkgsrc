# $NetBSD: Makefile,v 1.40 2006/12/28 12:12:57 joerg Exp $
#

DISTNAME=		gtksql-0.3
PKGREVISION=		7
CATEGORIES=		databases
MASTER_SITES=		http://membres.lycos.fr/bbrox/GtkSQL/ \
			${MASTER_SITE_SUNSITE:=X11/gtkbuffet/apps/gtksql/} \
			ftp://ftp.infodrom.north.de/pub/unix/gtkbuffet/apps/gtksql/ \
			ftp://ftp.loxinfo.co.th/pub/unix/database/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://membres.lycos.fr/bbrox/GtkSQL/
COMMENT=		Query tool for PostgreSQL written with GTK

USE_X11BASE=		yes
MAKE_ENV+=		MCFLAGS=${CFLAGS:M*:Q} PGSQL_PREFIX=${PGSQL_PREFIX:Q}

.include "../../mk/pgsql.buildlink3.mk"
.include "../../x11/gtk/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
