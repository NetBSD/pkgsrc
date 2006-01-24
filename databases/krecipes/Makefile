# $NetBSD: Makefile,v 1.3 2006/01/24 07:31:59 wiz Exp $
#

DISTNAME=		krecipes-0.8.1
PKGREVISION=		1
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
