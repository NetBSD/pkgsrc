# $NetBSD: Makefile,v 1.30 2010/06/13 22:44:49 wiz Exp $
#

DISTNAME=		nabi-0.99.3
PKGREVISION=		2
CATEGORIES=		korean inputmethod
MASTER_SITES=		http://kldp.net/frs/download.php/4929/

MAINTAINER=		minskim@NetBSD.org
HOMEPAGE=		http://nabi.kldp.net/
COMMENT=		X Input Method for Korean

PKG_DESTDIR_SUPPORT=	user-destdir

USE_TOOLS+=		pkg-config msgfmt
GNU_CONFIGURE=		YES
USE_PKGLOCALEDIR=	YES

.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../inputmethod/libhangul/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
