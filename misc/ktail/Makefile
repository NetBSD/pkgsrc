# $NetBSD: Makefile,v 1.3 2001/12/04 06:14:59 jlam Exp $

DISTNAME=	ktail-0.5.1
CATEGORIES=	misc kde
MASTER_SITES=	http://www.franken.de/users/duffy1/rjakob/

MAINTAINER=	zuntum@netbsd.org
HOMEPAGE=	http://www.franken.de/users/duffy1/rjakob/
COMMENT=	ktail monitors multiple files and/or command output in one window

BUILD_DEPENDS+=	qt2-designer-kde>=2.3.1nb1:../../x11/qt2-designer-kde

BUILD_USES_MSGFMT=      YES
USE_BUILDLINK_ONLY=	YES
GNU_CONFIGURE=		YES

.include "../../x11/kde2/buildlink.mk"
.include "../../x11/kdebase2/buildlink.mk"
.include "../../mk/x11.buildlink.mk"
.include "../../mk/bsd.pkg.mk"
