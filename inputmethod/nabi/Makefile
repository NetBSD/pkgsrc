# $NetBSD: Makefile,v 1.40.2.1 2012/10/03 12:08:23 spz Exp $
#

DISTNAME=		nabi-0.99.9
PKGREVISION=		5
CATEGORIES=		korean inputmethod
MASTER_SITES=		http://kldp.net/frs/download.php/5926/

MAINTAINER=		minskim@NetBSD.org
HOMEPAGE=		http://kldp.net/projects/nabi/
COMMENT=		X Input Method for Korean
LICENSE=		gnu-gpl-v2 # or later

PKG_DESTDIR_SUPPORT=	user-destdir

USE_TOOLS+=		pkg-config msgfmt
GNU_CONFIGURE=		YES
USE_PKGLOCALEDIR=	YES

.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
BUILDLINK_API_DEPENDS.libhangul+=	libhangul>=0.0.12
.include "../../inputmethod/libhangul/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
