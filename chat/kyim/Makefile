# $NetBSD: Makefile,v 1.7 2004/01/23 21:50:43 jmmv Exp $

DISTNAME=	kyim-1.0
PKGREVISION=	4
CATEGORIES=	chat kde
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=kyim/}
EXTRACT_SUFX=	.tgz

MAINTAINER=	jlam@NetBSD.org
HOMEPAGE=	http://kyim.sourceforge.net/
COMMENT=	KDE Yahoo! client

USE_BUILDLINK2=		YES
USE_GNU_TOOLS+=		make
GNU_CONFIGURE=          YES
CPPFLAGS+=		-DHAVE_STDARG_H=1

.include "../../x11/kde2/buildlink2.mk"
.include "../../x11/kdebase2/buildlink2.mk"

.include "../../mk/bsd.pkg.mk"
