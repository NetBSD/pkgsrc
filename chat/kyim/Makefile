# $NetBSD: Makefile,v 1.10 2004/05/03 03:48:04 snj Exp $

DISTNAME=	kyim-1.0
PKGREVISION=	5
CATEGORIES=	chat kde
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=kyim/}
EXTRACT_SUFX=	.tgz

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://kyim.sourceforge.net/
COMMENT=	KDE Yahoo! client

USE_BUILDLINK3=		YES
USE_GNU_TOOLS+=		make
GNU_CONFIGURE=          YES
CPPFLAGS+=		-DHAVE_STDARG_H=1

.include "../../x11/kde2/kde2.mk"
.include "../../x11/kdebase2/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
