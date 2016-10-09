# $NetBSD: Makefile,v 1.48 2016/10/09 21:41:56 wiz Exp $
#

DISTNAME=		gtksql-0.3
PKGREVISION=		11
CATEGORIES=		databases
MASTER_SITES=		http://membres.lycos.fr/bbrox/GtkSQL/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://membres.lycos.fr/bbrox/GtkSQL/
COMMENT=		Query tool for PostgreSQL written with GTK

INSTALLATION_DIRS+=	bin

MAKE_ENV+=		MCFLAGS=${CFLAGS:M*:Q} PGSQL_PREFIX=${PGSQL_PREFIX:Q}

.include "../../mk/pgsql.buildlink3.mk"
.include "../../x11/gtk/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
