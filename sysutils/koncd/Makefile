# $NetBSD: Makefile,v 1.8 2003/05/02 11:56:25 wiz Exp $

DISTNAME=	koncd-0.7.1
PKGREVISION=	2
CATEGORIES=	sysutils
MASTER_SITES=	${HOMEPAGE}download/

MAINTAINER=	wulf@netbsd.org
HOMEPAGE=	http://www.koncd.de/
COMMENT=	Frontend to the fabulous cdrecord and mkisofs programs

BUILD_DEPENDS+=	qt2-designer-kde>=2.3.1nb2:../../x11/qt2-designer-kde
DEPENDS+=	cdrecord>=1.9:../../sysutils/cdrecord

USE_BUILDLINK2=		YES
GNU_CONFIGURE=		YES

.include "../../x11/kde2/buildlink2.mk"
.include "../../x11/kdebase2/buildlink2.mk"

.include "../../mk/bsd.pkg.mk"
