# $NetBSD: Makefile,v 1.21 2005/10/14 14:28:57 minskim Exp $
#

DISTNAME=		nabi-0.15
CATEGORIES=		korean inputmethod
MASTER_SITES=		http://kldp.net/frs/download.php/1651/

MAINTAINER=		minskim@NetBSD.org
HOMEPAGE=		http://nabi.kldp.net/
COMMENT=		X Input Method for Korean

USE_TOOLS+=		pkg-config
GNU_CONFIGURE=		YES
USE_PKGLOCALEDIR=	YES

.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
