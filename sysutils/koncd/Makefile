# $NetBSD: Makefile,v 1.15 2004/10/03 00:18:15 tv Exp $

DISTNAME=	koncd-0.7.1
PKGREVISION=	7
CATEGORIES=	sysutils
MASTER_SITES=	${HOMEPAGE}download/

MAINTAINER=	wulf@NetBSD.org
HOMEPAGE=	http://www.koncd.de/
COMMENT=	Frontend to the fabulous cdrecord and mkisofs programs

BUILD_DEPENDS+=	qt2-designer-kde>=2.3.1nb2:../../x11/qt2-designer-kde
DEPENDS+=	cdrecord>=1.9:../../sysutils/cdrecord

USE_BUILDLINK3=		YES
GNU_CONFIGURE=		YES

.include "../../x11/kde2/kde2.mk"
.include "../../x11/kdebase2/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
