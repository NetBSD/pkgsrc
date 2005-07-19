# $NetBSD: Makefile,v 1.1.1.1 2005/07/19 17:10:36 drochner Exp $
#

DISTNAME=		krecipes_beta_0.8
PKGNAME=		krecipes-0.8beta
CATEGORIES=		databases
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=krecipes/}

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://krecipes.sourceforge.net/
COMMENT=		Recipe manager

WRKSRC=		${WRKDIR}/krecipes-0.8
USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes

.include "../../meta-pkgs/kde3/kde3.mk"
.include "../../x11/kdelibs3/buildlink3.mk"
.include "../../databases/sqlite3/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
