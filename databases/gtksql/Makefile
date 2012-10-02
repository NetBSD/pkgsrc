# $NetBSD: Makefile,v 1.46 2012/10/02 21:25:18 asau Exp $
#

DISTNAME=		gtksql-0.3
PKGREVISION=		10
CATEGORIES=		databases
MASTER_SITES=		http://membres.lycos.fr/bbrox/GtkSQL/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://membres.lycos.fr/bbrox/GtkSQL/
COMMENT=		Query tool for PostgreSQL written with GTK

INSTALLATION_DIRS+=	bin

USE_X11BASE=		yes
MAKE_ENV+=		MCFLAGS=${CFLAGS:M*:Q} PGSQL_PREFIX=${PGSQL_PREFIX:Q}

.include "../../mk/pgsql.buildlink3.mk"
.include "../../x11/gtk/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
