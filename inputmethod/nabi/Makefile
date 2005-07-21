# $NetBSD: Makefile,v 1.19 2005/07/21 16:29:52 wiz Exp $
#

DISTNAME=		nabi-0.15
CATEGORIES=		korean inputmethod
MASTER_SITES=		http://download.kldp.net/nabi/

MAINTAINER=		minskim@NetBSD.org
HOMEPAGE=		http://nabi.kldp.net/
COMMENT=		X Input Method for Korean

GNU_CONFIGURE=		YES
USE_PKGLOCALEDIR=	YES

.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/pkg-config/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
