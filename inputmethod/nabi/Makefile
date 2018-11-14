# $NetBSD: Makefile,v 1.58 2018/11/14 22:21:52 kleink Exp $
#

DISTNAME=		nabi-0.99.9
PKGREVISION=		21
CATEGORIES=		korean inputmethod
MASTER_SITES=		http://kldp.net/frs/download.php/5926/

MAINTAINER=		minskim@NetBSD.org
HOMEPAGE=		http://kldp.net/projects/nabi/
COMMENT=		X Input Method for Korean
LICENSE=		gnu-gpl-v2 # or later

USE_TOOLS+=		pkg-config msgfmt
GNU_CONFIGURE=		YES
USE_PKGLOCALEDIR=	YES

.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
BUILDLINK_API_DEPENDS.libhangul+=	libhangul>=0.0.12
.include "../../inputmethod/libhangul/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
