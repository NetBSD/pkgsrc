# $NetBSD: Makefile,v 1.1.1.1 2002/09/21 01:04:23 rh Exp $
#

DISTNAME=	gail-0.17
CATEGORIES=	devel gnome
MASTER_SITES=	${MASTER_SITE_GNOME:=2.0.1/sources/gail/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	jmmv@hispabsd.org
HOMEPAGE=	http://developer.gnome.org/projects/gap/
COMMENT=	GNOME Accessibility Implementation Library

BUILD_DEPENDS+=		gtk-doc>=0.6:../../textproc/gtk-doc

GNU_CONFIGURE=		yes
USE_BUILDLINK2=		yes
USE_GMAKE=		yes
USE_GNU_GETTEXT=	yes
USE_X11=		yes

USE_LIBTOOL=		yes
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool

post-extract:
	${MV} ${WRKSRC}/docs/reference/libgail-util/html/book1.html \
	    ${WRKSRC}/docs/reference/libgail-util/html/index.html

.include "../../devel/atk/buildlink2.mk"
.include "../../devel/gettext-lib/buildlink2.mk"
.include "../../graphics/libart2/buildlink2.mk"
.include "../../graphics/libgnomecanvas/buildlink2.mk"
.include "../../x11/gtk2/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
