# $NetBSD: Makefile,v 1.15 2004/11/25 19:11:58 minskim Exp $
#

DISTNAME=		nabi-0.14
PKGREVISION=	1
CATEGORIES=		korean inputmethod
MASTER_SITES=		http://download.kldp.net/nabi/

MAINTAINER=		minskim@NetBSD.org
HOMEPAGE=		http://nabi.kldp.net/
COMMENT=		X Input Method for Korean

USE_BUILDLINK3=		YES
USE_X11=		YES
GNU_CONFIGURE=		YES
USE_PKGLOCALEDIR=	YES

.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/pkgconfig/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
