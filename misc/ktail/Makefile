# $NetBSD: Makefile,v 1.5 2002/09/20 11:56:14 jlam Exp $

DISTNAME=	ktail-0.5.1
PKGREVISION=	1
CATEGORIES=	misc kde
MASTER_SITES=	http://www.franken.de/users/duffy1/rjakob/

MAINTAINER=	zuntum@netbsd.org
HOMEPAGE=	http://www.franken.de/users/duffy1/rjakob/
COMMENT=	ktail monitors multiple files and/or command output in one window

BUILD_DEPENDS+=	qt2-designer-kde>=2.3.1nb2:../../x11/qt2-designer-kde

BUILD_USES_MSGFMT=      YES
USE_BUILDLINK2=		YES
GNU_CONFIGURE=		YES

.include "../../x11/kde2/buildlink2.mk"
.include "../../x11/kdebase2/buildlink2.mk"

.include "../../mk/bsd.pkg.mk"
