# $NetBSD: Makefile,v 1.10 2004/01/22 08:24:28 grant Exp $

DISTNAME=	cervisia-1.4.1
PKGREVISION=	4
CATEGORIES=	devel kde
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=cervisia/}

MAINTAINER=	wulf@NetBSD.org
HOMEPAGE=	http://cervisia.sourceforge.net/
COMMENT=	Graphical frontend for the CVS client

BUILD_DEPENDS+=	qt2-designer-kde>=2.3.1nb2:../../x11/qt2-designer-kde

USE_BUILDLINK2=		YES
USE_GNU_TOOLS+=		make
GNU_CONFIGURE=		YES

.include "../../x11/kde2/buildlink2.mk"
.include "../../x11/kdelibs2/buildlink2.mk"

.include "../../mk/bsd.pkg.mk"
