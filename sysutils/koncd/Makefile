# $NetBSD: Makefile,v 1.4 2001/11/13 21:26:58 jlam Exp $

DISTNAME=	koncd-0.7.1
CATEGORIES=	sysutils
MASTER_SITES=	${HOMEPAGE}download/

MAINTAINER=	wulf@netbsd.org
HOMEPAGE=	http://www.koncd.de/
COMMENT=	Frontend to the fabulous cdrecord and mkisofs programs

BUILD_DEPENDS+=	qt2-designer-kde>=2.3.1nb1:../../x11/qt2-designer-kde
DEPENDS+=	cdrecord>=1.9:../../sysutils/cdrecord

USE_BUILDLINK_ONLY=	YES
AUTOMAKE_OVERRIDE=	YES
GNU_CONFIGURE=		YES

.include "../../x11/kde2/buildlink.mk"
.include "../../x11/kdebase2/buildlink.mk"
.include "../../mk/x11.buildlink.mk"
.include "../../mk/bsd.pkg.mk"
