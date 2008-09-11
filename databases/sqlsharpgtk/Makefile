# $NetBSD: Makefile,v 1.1.1.1 2008/09/11 13:12:34 kefren Exp $

DISTNAME=	sqlsharpgtk-0.4
CATEGORIES=	databases
MASTER_SITES=	http://forgeftp.novell.com/sqlsharpgtk/SQL-Sharp%20For%20GTK-Sharp%200.4/

MAINTAINER=	pkgsrc-users@pkgsrc.org
HOMEPAGE=	http://forge.novell.com/modules/xfmod/project/?sqlsharpgtk
COMMENT=	GUI client for entering and running SQL commands and scripts

GNU_CONFIGURE=	yes
USE_TOOLS+=	gmake
MAKE_JOBS_SAFE=	no

.include "../../lang/mono/buildlink3.mk"
.include "../../x11/gtk-sharp/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
