# $NetBSD: Makefile,v 1.25 2006/06/11 14:45:04 joerg Exp $
#

DISTNAME=		nabi-0.15
PKGREVISION=		3
CATEGORIES=		korean inputmethod
MASTER_SITES=		http://kldp.net/frs/download.php/1651/

MAINTAINER=		minskim@NetBSD.org
HOMEPAGE=		http://nabi.kldp.net/
COMMENT=		X Input Method for Korean

USE_TOOLS+=		pkg-config msgfmt
GNU_CONFIGURE=		YES
USE_PKGLOCALEDIR=	YES

.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
