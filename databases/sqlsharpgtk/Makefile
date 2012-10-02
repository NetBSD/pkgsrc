# $NetBSD: Makefile,v 1.10 2012/10/02 21:25:53 asau Exp $

DISTNAME=	sqlsharpgtk-0.4
PKGREVISION=	5
CATEGORIES=	databases
MASTER_SITES=	http://forgeftp.novell.com/sqlsharpgtk/SQL-Sharp%20For%20GTK-Sharp%200.4/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://forge.novell.com/modules/xfmod/project/?sqlsharpgtk
COMMENT=	GUI client for entering and running SQL commands and scripts

BROKEN=		Unbuildable for years and appears to be dead upstream.

GNU_CONFIGURE=	yes
USE_TOOLS+=	gmake pkg-config
MAKE_JOBS_SAFE=	no

.include "../../lang/mono/buildlink3.mk"
.include "../../x11/gtk-sharp/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
