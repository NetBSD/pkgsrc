# $NetBSD: Makefile,v 1.4 2002/03/13 17:36:47 fredb Exp $

DISTNAME=	cervisia-1.4.1
PKGREVISION=	1
CATEGORIES=	devel kde
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=cervisia/}

MAINTAINER=	wulf@netbsd.org
HOMEPAGE=	http://cervisia.sourceforge.net/
COMMENT=	Graphical frontend for the CVS client

BUILD_DEPENDS+=	qt2-designer-kde>=2.3.1nb2:../../x11/qt2-designer-kde

USE_BUILDLINK_ONLY=	YES
USE_GMAKE=		YES
GNU_CONFIGURE=		YES

.include "../../x11/kde2/buildlink.mk"
.include "../../x11/kdelibs2/buildlink.mk"
.include "../../mk/x11.buildlink.mk"
.include "../../mk/bsd.pkg.mk"
