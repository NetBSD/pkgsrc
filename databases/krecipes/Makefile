# $NetBSD: Makefile,v 1.2 2005/09/08 18:18:52 drochner Exp $
#

DISTNAME=		krecipes-0.8.1
CATEGORIES=		databases
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=krecipes/}

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://krecipes.sourceforge.net/
COMMENT=		Recipe manager

USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes

.include "../../meta-pkgs/kde3/kde3.mk"
.include "../../x11/kdelibs3/buildlink3.mk"
.include "../../databases/sqlite3/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
