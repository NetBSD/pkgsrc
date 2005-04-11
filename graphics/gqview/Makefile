# $NetBSD: Makefile,v 1.52 2005/04/11 21:46:04 tv Exp $

DISTNAME=	gqview-2.0.0
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
.include "../../devel/pkgconfig/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
