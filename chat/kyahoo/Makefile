# $NetBSD: Makefile,v 1.8 2002/03/13 17:36:42 fredb Exp $

DISTNAME=	kyahoo-0.7
PKGREVISION=	1
CATEGORIES=	chat kde
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=kyahoo/}
EXTRACT_SUFX=	.tgz

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://kyahoo.sourceforge.net/
COMMENT=	Yahoo! client for KDE

USE_BUILDLINK_ONLY=	YES
USE_GMAKE=              YES

GNU_CONFIGURE=          YES
CONFIGURE_ARGS+=	--with-libyahoo=${BUILDLINK_DIR}

.include "../../chat/libyahoo/buildlink.mk"
.include "../../x11/kde2/buildlink.mk"
.include "../../x11/kdebase2/buildlink.mk"
.include "../../mk/x11.buildlink.mk"
.include "../../mk/bsd.pkg.mk"
