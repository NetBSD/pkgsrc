# $NetBSD: Makefile,v 1.18 2004/12/14 19:53:48 minskim Exp $

DISTNAME=		devhelp-0.7
PKGREVISION=		10
CATEGORIES=		devel x11
MASTER_SITES=		${MASTER_SITE_GNOME:=sources/devhelp/0.7/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://www.imendio.com/projects/devhelp/
COMMENT=		Documentation viewer based on GNOME2

USE_BUILDLINK3=		yes
USE_DIRS+=		gnome2-1.5
USE_GNU_TOOLS+=		make
USE_LIBTOOL=		yes
USE_PERL5=		build
USE_PKGLOCALEDIR=	yes
USE_X11=		yes

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--with-html-widget=gtkhtml2

BUILDLINK_TRANSFORM+=	rm:-DG_DISABLE_DEPRECATED
BUILDLINK_TRANSFORM+=	rm:-DGTK_DISABLE_DEPRECATED

.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/libgnomeui/buildlink3.mk"
.include "../../devel/pkgconfig/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/devhelp
	${INSTALL_DATA} ${WRKSRC}/misc/devhelp.el ${WRKSRC}/misc/devhelp.vim \
		${PREFIX}/share/examples/devhelp
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/devhelp
	cd ${WRKSRC} && ${INSTALL_DATA} AUTHORS COPYING ChangeLog README TODO \
		${PREFIX}/share/doc/devhelp

.include "../../mk/bsd.pkg.mk"
