# $NetBSD: Makefile,v 1.8 2003/12/20 05:18:37 xtraeme Exp $
#

DISTNAME=		nabi-0.12
CATEGORIES=		korean inputmethod
MASTER_SITES=		http://download.kldp.net/nabi/

MAINTAINER=		minskim@bawi.org
HOMEPAGE=		http://nabi.kldp.net/
COMMENT=		X Input Method for Korean

USE_BUILDLINK2=		YES
USE_X11=		YES
GNU_CONFIGURE=		YES
USE_PKGLOCALEDIR=	YES

.include "../../converters/libiconv/buildlink2.mk"
.include "../../devel/gettext-lib/buildlink2.mk"
.include "../../devel/pkgconfig/buildlink2.mk"
.include "../../x11/gtk2/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
