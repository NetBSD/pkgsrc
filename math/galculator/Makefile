# $NetBSD: Makefile,v 1.3 2005/07/21 16:29:53 wiz Exp $
#

DISTNAME=		galculator-1.2.5
CATEGORIES=		math
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=galculator/}

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://galculator.sourceforge.net/
COMMENT=		Desktop calculator with scientific / RPN modes

USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes
USE_TOOLS+=		gmake

.include "../../devel/pkg-config/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../devel/libglade2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
