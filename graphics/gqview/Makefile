# $NetBSD: Makefile,v 1.54 2005/07/21 16:29:51 wiz Exp $

DISTNAME=	gqview-2.0.1
CATEGORIES=	graphics x11
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=gqview/}

MAINTAINER=	wiz@NetBSD.org
HOMEPAGE=	http://gqview.sourceforge.net/
COMMENT=	GTK2-based graphic file viewer

BUILD_USES_MSGFMT=	# defined

GNU_CONFIGURE=		# defined
USE_DIRS+=		xdg-1.1
USE_PKGLOCALEDIR=	# defined

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/pkg-config/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
