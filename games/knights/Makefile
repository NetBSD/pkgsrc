# $NetBSD: Makefile,v 1.20 2005/04/11 21:45:51 tv Exp $

DISTNAME=	knights-0.6
CATEGORIES=	games kde
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=knights/}

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://knights.sourceforge.net/
COMMENT=	Chess interface for KDE

USE_GNU_TOOLS+=		make
USE_LANGUAGES=		c c++
GNU_CONFIGURE=          YES
USE_LIBTOOL=            YES

.include "../../meta-pkgs/kde3/kde3.mk"
.include "../../x11/kdebase3/buildlink3.mk"
.include "../../x11/kdelibs3/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
