# $NetBSD: Makefile,v 1.3 2003/12/13 00:45:22 wiz Exp $

DISTNAME=		devhelp-0.7
PKGREVISION=		2
CATEGORIES=		devel x11
MASTER_SITES=		${MASTER_SITE_GNOME:=sources/devhelp/0.7/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		benedikt.meurer@unix-ag.uni-siegen.de
HOMEPAGE=		http://www.imendio.com/projects/devhelp/
COMMENT=		Documentation viewer based on GNOME2

DEPENDS+=		gnome2-dirs>=1.2:../../misc/gnome2-dirs

USE_BUILDLINK2=		yes
USE_GMAKE=		yes
USE_LIBTOOL=		yes
USE_PERL5=		build
USE_PKGLOCALEDIR=	yes
USE_X11=		yes
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--with-html-widget=gtkhtml2

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/devhelp
	${INSTALL_DATA} ${WRKSRC}/misc/devhelp.el ${WRKSRC}/misc/devhelp.vim \
		${PREFIX}/share/examples/devhelp
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/devhelp
	cd ${WRKSRC} && ${INSTALL_DATA} AUTHORS COPYING ChangeLog README TODO \
		${PREFIX}/share/doc/devhelp

.include "../../devel/libgnomeui/buildlink2.mk"
.include "../../www/libgtkhtml/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
