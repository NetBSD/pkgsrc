# $NetBSD: Makefile,v 1.14 2004/10/03 00:13:25 tv Exp $

DISTNAME=	cervisia-1.4.1
PKGREVISION=	7
CATEGORIES=	devel kde
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=cervisia/}

MAINTAINER=	wulf@NetBSD.org
HOMEPAGE=	http://cervisia.sourceforge.net/
COMMENT=	Graphical frontend for the CVS client

BUILD_DEPENDS+=	qt2-designer-kde>=2.3.1nb2:../../x11/qt2-designer-kde

USE_BUILDLINK3=		YES
USE_GNU_TOOLS+=		make
GNU_CONFIGURE=		YES

.include "../../x11/kde2/kde2.mk"
.include "../../x11/kdelibs2/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
