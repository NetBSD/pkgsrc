# $NetBSD: Makefile,v 1.1.1.1 2002/09/20 10:57:01 jlam Exp $

DISTNAME=	kyim-1.0
CATEGORIES=	chat kde
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=kyim/}
EXTRACT_SUFX=	.tgz

MAINTAINER=	jlam@netbsd.org
HOMEPAGE=	http://kyim.sourceforge.net/
COMMENT=	KDE Yahoo! client

USE_BUILDLINK2=		YES
USE_GMAKE=              YES
GNU_CONFIGURE=          YES
CPPFLAGS+=		-DHAVE_STDARG_H=1

.include "../../x11/kde2/buildlink2.mk"
.include "../../x11/kdebase2/buildlink2.mk"

.include "../../mk/bsd.pkg.mk"
