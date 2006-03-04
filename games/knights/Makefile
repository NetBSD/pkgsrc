# $NetBSD: Makefile,v 1.25 2006/03/04 21:29:42 jlam Exp $

DISTNAME=	knights-0.6
PKGREVISION=	3
CATEGORIES=	games kde
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=knights/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://knights.sourceforge.net/
COMMENT=	Chess interface for KDE

USE_TOOLS+=		gmake
USE_LANGUAGES=		c c++
GNU_CONFIGURE=          YES
USE_LIBTOOL=            YES

.include "../../meta-pkgs/kde3/kde3.mk"
.include "../../x11/kdebase3/buildlink3.mk"
.include "../../x11/kdelibs3/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
