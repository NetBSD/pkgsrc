# $NetBSD: Makefile,v 1.13 2004/10/03 00:13:00 tv Exp $

DISTNAME=	ktail-0.5.1
PKGREVISION=	7
CATEGORIES=	misc kde
MASTER_SITES=	http://www.franken.de/users/duffy1/rjakob/

MAINTAINER=	zuntum@NetBSD.org
HOMEPAGE=	http://www.franken.de/users/duffy1/rjakob/
COMMENT=	ktail monitors multiple files and/or command output in one window

BUILD_DEPENDS+=	qt2-designer-kde>=2.3.1nb2:../../x11/qt2-designer-kde

BUILD_USES_MSGFMT=      YES
USE_BUILDLINK3=		YES
GNU_CONFIGURE=		YES

.include "../../x11/kde2/kde2.mk"
.include "../../x11/kdebase2/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
