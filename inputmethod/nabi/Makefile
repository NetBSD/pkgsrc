# $NetBSD: Makefile,v 1.11 2004/02/10 17:05:54 minskim Exp $
#

DISTNAME=		nabi-0.12
PKGREVISION=		1
CATEGORIES=		korean inputmethod
MASTER_SITES=		http://download.kldp.net/nabi/

MAINTAINER=		minskim@bawi.org
HOMEPAGE=		http://nabi.kldp.net/
COMMENT=		X Input Method for Korean

USE_BUILDLINK3=		YES
USE_X11=		YES
GNU_CONFIGURE=		YES
USE_PKGLOCALEDIR=	YES

SUBST_CLASSES+=		options
SUBST_MESSAGE.options=	"Removing incompatible compiler options."
SUBST_STAGE.options=	post-patch
SUBST_FILES.options=	IMdkit/Makefile.in src/Makefile.in
SUBST_SED.options=	-e 's,-Wall,,g'

.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/pkgconfig/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
