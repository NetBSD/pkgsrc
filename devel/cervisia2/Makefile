# $NetBSD: Makefile,v 1.5 2002/09/20 11:26:26 jlam Exp $

DISTNAME=	cervisia-1.4.1
PKGREVISION=	1
CATEGORIES=	devel kde
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=cervisia/}

MAINTAINER=	wulf@netbsd.org
HOMEPAGE=	http://cervisia.sourceforge.net/
COMMENT=	Graphical frontend for the CVS client

BUILD_DEPENDS+=	qt2-designer-kde>=2.3.1nb2:../../x11/qt2-designer-kde

USE_BUILDLINK2=		YES
USE_GMAKE=		YES
GNU_CONFIGURE=		YES

.include "../../x11/kde2/buildlink2.mk"
.include "../../x11/kdelibs2/buildlink2.mk"

.include "../../mk/bsd.pkg.mk"
